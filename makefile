all:
	g++ -std=c++17 -o main main.cpp $(wildcard src/classes/*.cpp)