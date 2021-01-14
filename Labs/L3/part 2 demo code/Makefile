OBJ = main.o address.o person.o

myApp: $(OBJ)
	g++ -o myApp $(OBJ)

main.o: main.cpp
	g++ -g -Wall -c main.cpp

address.o: address.cpp
	g++ -g -Wall -c address.cpp

person.o: person.cpp
	g++ -g -Wall -c person.cpp

clean:
	rm -f $(OBJ) myApp