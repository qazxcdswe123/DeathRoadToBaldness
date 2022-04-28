recipe = Reader.o Book.o BDatabase.o RDatabase.o library.o

output : $(recipe)
	g++ -o output -g -Wall $(recipe)

Reader.o : Reader.h 

Book.o : Book.h
	
BDatabase.o : BDatabase.h 
	
RDatabase.o : RDatabase.h

library.o : library.cpp

.PHONY : clean
clean : 
	-rm output $(recipe)