#include <string.h>
#include <stdlib.h>

#include "../include/crypto.h"
#include "../external/GmSSL/include/gmssl/sm3.h"
#include "../external/GmSSL/include/gmssl/sm4.h"
#include "../external/GmSSL/include/gmssl/rand.h"

int pbkdf2_sm3(const char *password, size_t password_len, const uint8_t *salt, size_t salt_len, uint8_t *key) {
    if (gmssl_pbkdf2_hmac_sm3(password, password_len, salt, salt_len, PBKDF2_ITERATION, SM4_KEY_LENGTH, key) != 0x1) {
        fprintf(stderr, "PBKDF2密钥派生失败");

        return -0x1;
    }

    return 0x0;
}

int generate_random_bytes(uint8_t *data, size_t len) {
    if (gmssl_rand_bytes(data, len) != 0x1) {
        fprintf(stderr, "生成随机数失败");
        return -0x1;
    }

    return 0x0;
}