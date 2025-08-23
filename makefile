# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -O2 -Iinclude -Iexternal/GmSSL/include/gmssl
DEBUGFLAGS = -g -DDEBUG
LDFLAGS = -lgmssl

# Directories
SRCDIR = src
BINDIR = bin
OBJDIR = obj

# Source files
SRC = $(wildcard $(SRCDIR)/*.c)
OBJ = $(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

# Target executable
TARGET = $(BINDIR)/sm3file

# Default target
all: directories $(TARGET)

# Create necessary directories
directories:
	@mkdir -p $(BINDIR) $(OBJDIR)

# Build target
$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $@ $(LDFLAGS)

# Compile source files
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Debug build
debug: CFLAGS += $(DEBUGFLAGS)
debug: clean all

# Clean build files
clean:
	@rm -rf $(BINDIR) $(OBJDIR)

# Install target
install: all
	@mkdir -p $(DESTDIR)/usr/local/bin
	@cp $(TARGET) $(DESTDIR)/usr/local/bin/

# Uninstall target
uninstall:
	@rm -f $(DESTDIR)/usr/local/bin/sm3file

.PHONY: all debug clean install uninstall directories
