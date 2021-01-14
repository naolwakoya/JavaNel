OBJ = main.o Control.o Str_Utils.o UI.o Parse.o

myTunes: $(OBJ)
	g++ -o myTunes $(OBJ)

main.o: main.cpp
	g++ -g -Wall -c main.cpp

Control.o: Control.cpp
	g++ -g -Wall -c Control.cpp

Str_Utils.o: Str_Utils.cpp
	g++ -g -Wall -c Str_Utils.cpp

UI.o: UI.cpp
	g++ -g -Wall -c UI.cpp

Parse.o : Parse.cpp
	g++ -g -Wall -c Parse.cpp

clean:
	rm -f $(OBJ) myTunes