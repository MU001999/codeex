SRC = $(wildcard ./Src/*.cpp)

test: ./Bin/Lab_3
	./Bin/Lab_3

./Bin/Lab_3: ${SRC} | ./Bin/
	g++ -std=c++17 $^ -lpthread -o $@

./Bin/:
	mkdir Bin

.PHONY: clean
clean:
	rm -rf ./Bin
