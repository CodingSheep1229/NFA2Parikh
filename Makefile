#declare variables
CXX = g++
INCLUDE = .
FLAGS = -O3 -g -Wall -ansi

all : clean main.o NFA.o ExpTree.o 
	$(CXX) -o bin/NFA2Parikh main.o NFA.o ExpTree.o
	rm -f *.o

run: all 
	./NFA2Parikh > out;cat out;z3 out

main.o: main.cpp NFA.h ExpTree.h
	$(CXX) -I$(INCLUDE) $(FLAGS) -c main.cpp

NFA.o: NFA.cpp NFA.h ExpTree.h
	$(CXX) -I$(INCLUDE) $(FLAGS) -c NFA.cpp 

ExpTree.o: ExpTree.cpp ExpTree.h
	$(CXX) -I$(INCLUDE) $(FLAGS) -c ExpTree.cpp 

clean:
	rm -f bin/*