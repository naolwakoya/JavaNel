OBJ = main.o sqlite3.o

myApp: $(OBJ)
	g++ -o myApp $(OBJ) -lpthread -ldl

main.o:	main.cpp
	g++ -c main.cpp

sqlite3.o:	sqlite3.c sqlite3.h
	gcc -c sqlite3.c

clean:
	rm -f $(OBJ) myApp