COMP 2404 - Introduction to Software Engineering
				Assignment 1

@author(s) 
Kaleb Tesfay
Student Number: 101048170

Naol Gushu
Student Number: 100911600

Professor. Lou Nel

************************
A message from author(s):
	Coded with <3,	  
************************

Compilation Cmd:
	- To compile, you will need to access the respected directory all the files are located in.
        cd src 
		- Once you are in the respected directory, you'll need to run the Makefile.
			- make
		- Once you ran the Make, it'll create an updated version of all the object files.
			- It'll create a big object file called cal, which is all the program's object files 
			into one.
				- Run...
					- ./myTunes


Lanching and Operating Instructions:
	- Once the code is ran...
		- ./myTunes
			- It will show the main menu.

				- COMMANDS
                    - add
                        - Add data to collections
                    - delete
                        - Delete data from collections
                    - show
                        - Show entries in collections

                - UI SHELL COMMANDS
				    - .quit
					    - Quits program.
                    - .read
                        - Read a script file
                    - .log
                        - output goes into log.txt file
                        - log commands
                            - .log clear
                            - .log start
                            - .log start_output
                            - .log start_both
                            - .log stop 
                            - .log save 
                            - .log show
                            
                    - .help
                        - Shows the help menu

                - DEVELOPER COMMANDS
                    - .trim
                        - Trims the arugment
                    - .startsWith
                        - Tests string prefix
                    - .endsWith
                        - Test string suffix
                    - .toTitleCase
                        - Returns title cased string