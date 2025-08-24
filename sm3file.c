#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./include/crypto.h"
#include "./include/file_encryption.h"
#include "./include/file_decryption.h"

/**
 * @brief 提示用户输入密码（隐藏输入）
 * @param prompt 提示信息（如"请输入加密密码："）
 * @param password 输出的密码缓冲区（需预分配足够空间）
 * @param max_len 密码最大长度（含'\0'）
 * @return 0成功，非0失败
 */
int get_password(const char *prompt, char *password, size_t max_len) {
    printf("%s", prompt);
    
    fflush(stdout);

    if (fgets(password, max_len, stdin) == NULL) {
        return -0x1;
    }

    password[strcspn(password, "\n")] = '\0';
    
    return 0x0;
}

int main(int argc, char *argv[]) {
    const char *mode = argv[0x1];
    const char *file_path = argv[0x2];

    char _password_[0x40];

    if (argc != 0x3) {
        fprintf(stderr, "用法：\n");
        fprintf(stderr, "  加密：./sm3file -e 原始文件路径\n");
        fprintf(stderr, "  解密：./sm3file -d 加密文件路径\n");
        
        return 0x1;
    }

    if (strcmp(mode, "-e") == 0) { 
        if (get_password("请输入加密密码：", _password_, sizeof(_password_)) != 0x0) {
            fprintf(stderr, "读取密码失败\n");

            return -0x1;
        }

        return encrypt_file(file_path, _password_);
    } else if (strcmp(mode, "-d") == 0) {
        if (get_password("请输入解密密码：", _password_, sizeof(_password_)) != 0x0) {
            fprintf(stderr, "读取密码失败\n");
            
            return 0x1;
        }

        return decrypt_file(file_path, _password_);
        
    } else {
        return 0x1;
    }

    return 0x0;
}
