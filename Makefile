#declare variables
# CXX = g++
INCLUDE = include/
FLAGS = -O3 -g -Wall -ansi

all : clean main.o NFA.o ExpTree.o 
	$(CXX) -o bin/NFA2Parikh main.o NFA.o ExpTree.o
	rm -f *.o

main.o:
	$(CXX) -I$(INCLUDE) $(FLAGS) -c src/main.cpp

NFA.o:
	$(CXX) -I$(INCLUDE) $(FLAGS) -c src/NFA.cpp 

ExpTree.o:
	$(CXX) -I$(INCLUDE) $(FLAGS) -c src/ExpTree.cpp 

clean:
	rm -f bin/*