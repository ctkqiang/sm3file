#pragma once

#ifndef CRYPTO_H
#define CRYPTO_H

#include <stdint.h>
#include <stddef.h>

#define SM3_DIGEST_ENGTH 0x20       // 这是SM3哈希的摘要长度
#define SM4_KEY_LENGTH 0x10         // 这是SM4密钥的长度
#define SM4_BLOCK_LENGTH 0x10       // 这是SM4加密块的长度
#define SM4_CBC_IV_LENGTH 0x10      // 这是SM4 CBC模式下的IV长度
#define PBKDF2_ITERATION 0x186A0    // 这是PBKDF2的迭代次数，为了增强安全性。

/**
 * @brief 使用PBKDF2-HMAC-SM3从密码派生密钥
 * @param password 用户密码（需以'\0'结尾）
 * @param password_len 密码长度
 * @param salt 盐值（随机生成）
 * @param salt_len 盐值长度（推荐16字节）
 * @param key 输出的派生密钥（需预分配SM4_KEY_LEN字节）
 * @return 0成功，非0失败
 */
int pbkdf2_sm3(const char *password, size_t password_len, const uint8_t *salt, size_t salt_len, uint8_t *key);

/**
 * @brief 生成随机字节数组（用于盐值/IV）
 * @param data 输出的随机数据（需预分配内存）
 * @param len 随机数据长度
 * @return 0成功，非0失败
 */
int generate_random_bytes(uint8_t *data, size_t len);

#endif