CC = gcc
CFLAGS = -Wall -Wextra -Iinclude `pkg-config --cflags gtk4`
LDFLAGS = `pkg-config --libs gtk4` -mwindows

SRC = $(wildcard src/*.c)
OBJ = $(SRC:.c=.o)
TARGET = VoidKey

all: clean $(TARGET)

$(TARGET): $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	@echo "跳过对象文件删除"

.PHONY: all clean
