TARGET = annealing


all: $(TARGET)




$(TARGET): main.o Solution.o algorithm.o
	g++ -o $(TARGET) main.o Solution.o algorithm.o
main.o: main.cpp
	g++ -c -o main.o main.cpp
Solution.o: Solution.cpp
	g++ -c -o Solution.o Solution.cpp
algorithm.o: algorithm.cpp
	g++ -c -o algorithm.o algorithm.cpp

clear:
	rm *.o 
