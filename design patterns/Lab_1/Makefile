SRC = $(wildcard ./src/*.cpp)

./bin/lab_1: ${SRC} | ./bin/
	g++ -std=c++17 $^ -o $@

./bin/:
	mkdir bin

.PHONY: clean
clean:
	rm -rf ./bin
