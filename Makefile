CXX=g++
CXXFLAGS= \
	-std=c++11 \
	-Wall \
	-Wextra \
	-Wpedantic \
	-Werror \
	-Wfatal-errors \
	-I.src/
CXXNC=-lncurses

all: \
	main.bin
	./main.bin

clean:
	rm -f main.bin
	rm -f src/*.o

main.bin: src/main.cpp src/gra.o
	$(CXX) $(CXXFLAGS) -o $@ $^ $(CXXNC)

gra.o: src/gra.cpp src/gra.hpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<
