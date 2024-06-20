CXX = g++
CXXFLAGS = -std=c++11

all: tree 

tree: Demo.o
	$(CXX) $(CXXFLAGS) -o tree Demo.o

test: Test.o
	$(CXX) $(CXXFLAGS) -o test test_Demo.o

Demo.o: Demo.cpp Tree.hpp TreeNode.hpp TreeIterator.hpp
	$(CXX) $(CXXFLAGS) -c Demo.cpp

Test.o: test_Demo.cpp Tree.hpp TreeNode.hpp TreeIterator.hpp
	$(CXX) $(CXXFLAGS) -c test_Demo.cpp

valgrind:
	valgrind --leak-check=full ./tree	

clean:
	rm -f *.o tree
