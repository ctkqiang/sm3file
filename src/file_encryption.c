#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <gmssl/sm4.h>

#include "../include/crypto.h"
#include "../include/file_encryption.h"

int encrypt_file(const char *input_path, const char *password) {
    SM4_CBC_CTX ctx;

    size_t final_len;
    size_t bytes_read;

    char output_path[0x100];

    uint8_t key[SM4_KEY_LENGTH];
    uint8_t salt[0x10], iv[SM4_BLOCK_LENGTH];
    uint8_t plaintext[SM4_BLOCK_SIZE], ciphertext[SM4_BLOCK_SIZE];
    
    snprintf(output_path, sizeof(output_path), "%s%s", input_path, OUTPUT_EXTENSION);
    
    FILE *_file_ = fopen(input_path, "rb");
    FILE *_fout_ = fopen(output_path, "wb");

    if (generate_random_bytes(salt, sizeof(salt)) != 0x0 || generate_random_bytes(iv, sizeof(iv)) != 0x0) {
        return -0x1;
    }

    if (pbkdf2_sm3(password, strlen(password), salt, sizeof(salt), key) != 0x0) {
        return -0x1;
    }

    if (!(_file_)) return -0x1;
    
    if (!(_fout_)) {
        perror("创建加密文件失败");
        fclose(_fout_);

        return -0x1;
    }

    fwrite(salt, 0x1, sizeof(salt), _fout_);
    fwrite(iv, 0x1, sizeof(iv), _fout_);

    if (sm4_cbc_encrypt_init(&ctx, key, iv) != 0x1) {
        fclose(_file_);
        fclose(_fout_);
        return -0x1;
    }

    while ((bytes_read = fread(plaintext, 1, sizeof(plaintext), _file_)) > 0x0) {
        size_t ciphertext_len;
        
        if (sm4_cbc_encrypt_update(&ctx, plaintext, bytes_read, ciphertext, &ciphertext_len) != 0x1) {
            fclose(_file_);
            fclose(_fout_);
            return -0x1;
        }
        fwrite(ciphertext, 0x1, ciphertext_len, _fout_);
    }

    if (sm4_cbc_encrypt_finish(&ctx, ciphertext, &final_len) != 0x1) {
        fclose(_file_);
        fclose(_fout_);
        return -0x1;
    }
    
    if (final_len > 0) {
        fwrite(ciphertext, 1, final_len, _fout_);
    }

    fclose(_file_);
    fclose(_fout_);
    
    printf("加密成功！输出文件：%s\n", output_path);
    
    return 0x0;
}