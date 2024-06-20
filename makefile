CXX = g++
CXXFLAGS = -std=c++11

all: tree

tree: Demo.o
	$(CXX) $(CXXFLAGS) -o tree Demo.o

Demo.o: Demo.cpp
	$(CXX) $(CXXFLAGS) -c Demo.cpp

clean:
	rm -f *.o tree
