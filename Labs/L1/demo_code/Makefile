OBJ = main.o Person.o Pet.o 

tut1: $(OBJ)
	g++ -o tut1 $(OBJ)

main.o: main.cpp
	g++ -g -Wall -c main.cpp

Person.o: Person.cpp
	g++ -g -Wall -c Person.cpp

Pet.o: Pet.cpp
	g++ -g -Wall -c Pet.cpp

clean:
	rm -f $(OBJ) tut1
