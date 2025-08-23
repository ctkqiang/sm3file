#include <string.h>
#include <stdlib.h>

#include "../include/crypto.h"
#include "../external/GmSSL/include/gmssl/sm3.h"

int pbkdf2_sm3(const char *password, size_t password_len, const uint8_t *salt, size_t salt_len, uint8_t *key) {
    
}