CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra -Werror -pedantic

all: Main test

main: main.cpp MyContainer.hpp
	$(CXX) $(CXXFLAGS) -o Main main.cpp
	./Main

test: TestMyContainer.cpp MyContainer.hpp
	$(CXX) $(CXXFLAGS) -o test TestMyContainer.cpp
	./test

valgrind: TestMyContainer.cpp MyContainer.hpp
	$(CXX) $(CXXFLAGS) -o test TestMyContainer.cpp
	valgrind --leak-check=full ./test

clean:
	rm -f Main test
