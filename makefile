CXX = g++
CXXFLAGS = -std=c++11
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

all: tree test

tree: Demo.o
	$(CXX) $(CXXFLAGS) -o tree Demo.o $(LDFLAGS)

test: Test.o
	$(CXX) $(CXXFLAGS) -o test test_Demo.o $(LDFLAGS)

Demo.o: Demo.cpp Tree.hpp TreeNode.hpp TreeIterator.hpp
	$(CXX) $(CXXFLAGS) -c Demo.cpp

Test.o: test_Demo.cpp Tree.hpp TreeNode.hpp TreeIterator.hpp
	$(CXX) $(CXXFLAGS) -c test_Demo.cpp

valgrind:
	valgrind --leak-check=full ./tree	

clean:
	rm -f *.o tree
