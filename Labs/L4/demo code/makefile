OBJ = main.o person.o emailaddress.o date.o  collection.o

myApp:	$(OBJ)
	g++ -o myApp $(OBJ)

main.o: main.cpp
	g++ -c main.cpp

person.o: person.cpp person.h
	g++ -c person.cpp

emailaddress.o: emailaddress.cpp emailaddress.h
		g++ -c emailaddress.cpp

date.o: date.cpp date.h
		g++ -c date.cpp

collection.o: collection.cpp collection.h
				g++ -c collection.cpp

clean:
	rm -f $(OBJ) myApp
