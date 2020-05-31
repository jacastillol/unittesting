CC=g++
CXXFLAGS=-std=c++17
INCLUDE_PATH=-I../../deps/include -I.

test_reader: test_reader.cpp reader.o
	$(CC) $(CXXFLAGS) $(INCLUDE_PATH) test_reader.cpp reader.o -o test_reader

reader.o: reader/reader.hpp reader/reader.cpp
	$(CC) $(CXXFLAGS) $(INCLUDE_PATH) -c reader/reader.cpp
