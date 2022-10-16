INC=-I./include

all: polynomial main
		g++ $(INC) build/polynomial.o build/main.o -o build/polynomial

main: main.cc
		g++ $(INC) main.cc -c -o build/main.o

polynomial: polynomial.h polynomial.cc
		g++ $(INC) polynomial.cc -c -o build/polynomial.o

clean:
		rm -rf build/*
