
prog: main.o InventoryRecord.o
	g++ -g -Wall -std=c++11 main.o InventoryRecord.o -o ourProg

main.o: main.cpp RedBlackTree.hpp InventoryRecord.hpp
	g++ -g -Wall -std=c++11 -c main.cpp 

InventoryRecord.o: InventoryRecord.cpp InventoryRecord.hpp
	g++ -g -Wall -std=c++11 -c InventoryRecord.cpp

clean: 
	-rm *.o

run:
	@./ourProg
