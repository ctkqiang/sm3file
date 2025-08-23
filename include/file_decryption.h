#pragma once

#ifndef FILE_DECRYPTION_H
#define FILE_DECRYPTION_H

/**
 * @brief 解密文件（主逻辑）
 * @param input_path 加密文件路径（格式：原始文件名.4599）
 * @param password 用户密码
 * @return 0成功，非0失败
 */
int decrypt_file(const char *input_path, const char *password);

#endif