CC=gcc
CFLAGS=-Wall -Iinclude

SRC=src/crypto.c src/file_encryption.c src/file_decrypttion.c
OBJ=$(SRC:.c=.o)

sm3file: $(OBJ)
	$(CC) -o $@ $(OBJ) $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f src/*.o sm3file.o sm3file
