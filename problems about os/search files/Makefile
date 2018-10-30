SRC = $(wildcard *.cpp)

TARGET = sf

BIN_TARGET = $(TARGET)

CC = g++
CFLAGS = -g -Wall -std=c++11

${BIN_TARGET}: ${SRC}
	${CC} ${CFLAGS} ${SRC} -o $@

.PHONY: clean
clean:
	rm -rf ${TARGET} sources content
