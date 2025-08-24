CC = gcc
CFLAGS = -Wall -Wextra -O2 -Iinclude -Iexternal/GmSSL/
LDFLAGS = -Lexternal/GmSSL/ -lgmssl

SRCS = sm3file.c src/crypto.c src/file_encryption.c src/file_decryption.c
OBJS = $(SRCS:%.c=obj/%.o)
TARGET = bin/sm3file

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	@mkdir -p bin
	$(CC) $(OBJS) -o $(TARGET) $(LDFLAGS)

obj/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf obj bin