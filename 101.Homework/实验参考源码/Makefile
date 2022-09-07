forAll = ycymain.cpp 

chapter2 = ch2/linearList.cpp 

ch2.o: $(forAll) $(chapter2)
	clang++ -c $(forAll) $(chapter2) 
	
main: ch2.o
	clang++ -o main ch2.o

.PHONY : clean
clean :
	-rm  main *.o