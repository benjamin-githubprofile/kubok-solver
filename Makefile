CXX = g++
CXXFLAGS = -Wall -std=c++11

all: kubok

kubok: main.o kubok_solver.o file_parser.o
	$(CXX) $(CXXFLAGS) -o kubok main.o kubok_solver.o file_parser.o

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp

kubok_solver.o: kubok_solver.cpp kubok_solver.h
	$(CXX) $(CXXFLAGS) -c kubok_solver.cpp

file_parser.o: file_parser.cpp file_parser.h
	$(CXX) $(CXXFLAGS) -c file_parser.cpp

clean:
	rm -f *.o kubok