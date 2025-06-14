##//elidnana@gmail.com

CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic -I.

# קובצי המקור (ללא מימושים ב-cpp של template)
COMMON_SRCS = MyContainer.h AscendingOrder.h DescendingOrder.h ReverseOrder.h SideCrossOrder.h MiddleOutOrder.h Order.h

# יעדים עיקריים
all: Main Test

Main: main.o
	$(CXX) $(CXXFLAGS) -o Main main.o

test: Test.o
	$(CXX) $(CXXFLAGS) -o Test Test.o

main.o: main.cpp $(COMMON_SRCS)
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

Test.o: Test.cpp $(COMMON_SRCS)
	$(CXX) $(CXXFLAGS) -c Test.cpp -o Test.o

clean:
	rm -f *.o Main Test

valgrind:
	make Main
	valgrind --leak-check=full ./Main


.PHONY: all clean Main Test valgrind
