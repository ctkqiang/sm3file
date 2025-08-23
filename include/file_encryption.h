#pragma once

#ifndef FILE_ENCRYPTION_H
#define FILE_ENCRYPTION_H

#define OUTPUT_EXTENSION ".smf"    // 这是加密文件的扩展名

/**
 * @brief 加密文件（主逻辑）
 * @param input_path 原始文件路径
 * @param password 用户密码
 * @return 0成功，非0失败
 */
int encrypt_file(const char *input_path, const char *password);

#endif