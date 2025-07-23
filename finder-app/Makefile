# Compiler and flags
CC := $(CROSS_COMPILE)gcc
CFLAGS := -Wall -Werror

# Output binary and source
TARGET := writer
SRC := writer.c
OBJ := writer.o

# Default target
all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

# Clean target
clean:
	rm -f $(TARGET) *.o

.PHONY: all clean
