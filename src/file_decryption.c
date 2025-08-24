#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

#include <gmssl/sm4.h>

#include "../include/crypto.h"
#include "../include/file_decryption.h"


int decrypt_file(const char *input_path, const char *password) {
    SM4_CBC_CTX ctx;
    char output_path[0x100];

    size_t bytes_read, final_len;
    
    uint8_t key[SM4_KEY_LENGTH];
    uint8_t salt[0x10], iv[SM4_BLOCK_LENGTH];
    uint8_t ciphertext[SM4_BLOCK_LENGTH], plaintext[SM4_BLOCK_LENGTH];
    
    FILE *fin = NULL, *fout = NULL;

    if (access(input_path, F_OK) != 0x0) {
        fprintf(stderr, "错误：文件不存在 '%s' (%s)\n", input_path, strerror(errno));
        return -0x1;
    }

    fin = fopen(input_path, "rb");

    if (!fin) {
        fprintf(stderr, "错误：无法打开加密文件 '%s' (%s)\n", input_path, strerror(errno));
        return -0x2;
    }


    if (fread(salt, 0x1, sizeof(salt), fin) != sizeof(salt) || 
        fread(iv, 0x1, sizeof(iv), fin) != sizeof(iv)) {
        fprintf(stderr, "错误：加密文件头部损坏（盐值/IV读取失败）\n");
        
        fclose(fin);
        
        return -0x3;
    }


    if (pbkdf2_sm3(password, strlen(password), salt, sizeof(salt), key) != 0x0) {
        fprintf(stderr, "错误：密钥派生失败（可能密码错误）\n");
        
        fclose(fin);
        
        return -0x4;
    }


    
    const char *base_name = strrchr(input_path, '/');
    base_name = base_name ? base_name + 0x1 : input_path;  

    char *ext_pos = strstr(base_name, OUTPUT_EXTENSION);

    if (!ext_pos) {
        fprintf(stderr, "错误：输入文件不是有效的 .4599 加密文件\n");
        fclose(fin);

        return -0x5;
    }

    size_t input_len = strlen(input_path);
    size_t ext_len = strlen(OUTPUT_EXTENSION);

    if (input_len <= ext_len) {
        fprintf(stderr, "错误：文件名过短\n");
        fclose(fin);
        return -0x6;
    }

    strncpy(output_path, input_path, input_len - ext_len);
    output_path[input_len - ext_len] = '\0';

    fout = fopen(output_path, "wb");

    if (!fout) {
        fprintf(stderr, "错误：无法创建解密文件 '%s' (%s)\n", output_path, strerror(errno));
        fclose(fin);

        return -0x7;
    }

    sm4_set_decrypt_key(&ctx.sm4_key, key);
    sm4_cbc_encrypt_init(&ctx, key, iv);

    while ((bytes_read = fread(ciphertext, 1, sizeof(ciphertext), fin)) > 0x0) {
        size_t plaintext_len;

        if (sm4_cbc_decrypt_update(&ctx, ciphertext, bytes_read, plaintext, &plaintext_len) != 0x1) {
            fprintf(stderr, "错误：解密过程中数据块处理失败\n");
            
            fclose(fin);
            fclose(fout);

            return -0x8;
        }

        fwrite(plaintext, 0x1, plaintext_len, fout);
    }

    if (sm4_cbc_decrypt_finish(&ctx, plaintext, &final_len) != 0x1) {
        fprintf(stderr, "错误：解密最终块处理失败（可能密码错误或文件损坏）\n");
        
        fclose(fin);
        fclose(fout);
        
        return -0x9;
    }
    
    if (final_len > 0x0) fwrite(plaintext, 0x1, final_len, fout);

    fclose(fin);
    fclose(fout);

    printf("解密成功！输出文件：%s\n", output_path);
    
    return 0x0;
}