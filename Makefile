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
	rm -f src/*.o

clean:
	rm -f main.bin
	rm -f src/*.o

git:
	git add Makefile src/main.cpp src/gra.cpp src/gra.hpp source/plansze.bin

main.bin: src/main.cpp src/gra.o
	$(CXX) $(CXXFLAGS) -o $@ $^ $(CXXNC)

gra.o: src/gra.cpp src/gra.hpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<
