SRC = $(wildcard ./Src/*.cpp)

./Bin/Lab_3: ${SRC} | ./Bin/
	g++ -std=c++17 $^ -o $@

./Bin/:
	mkdir Bin

.PHONY: clean
clean:
	rm -rf ./Bin
