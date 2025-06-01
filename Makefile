CC = gcc
CFLAGS = -Wall -std=c11 -Iinclude -D_POSIX_C_SOURCE=200809L -D_XOPEN_SOURCE=700 `pkg-config --cflags gtk4`
LDFLAGS = -mwindows `pkg-config --libs gtk4`

SRC = src/main.c src/application.c src/main_window.c src/password_generator.c src/file_reader.c
OBJ = $(SRC:.c=.o)
TARGET = Voidkey

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %..c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all clean
