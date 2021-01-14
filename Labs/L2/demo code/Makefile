OBJ = main.o Str_Utils.o

t2: $(OBJ)
	g++ -o t2 $(OBJ)

main.o: main.cpp
	g++ -g -Wall -c main.cpp

str_utils..o: Str_Utils.cpp
	g++ -g -Wall -c Str_Utils.cpp

clean:
	rm -f $(OBJ) t2