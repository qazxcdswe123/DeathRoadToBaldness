Time : Time.o TestTime.cpp
	g++ -o Time -g -Wall Time.o TestTime.cpp

Time.o : Time.h Time.cpp
	g++ -c -g -Wall Time.cpp
	
.PHONY : clean
clean : 
	-rm Time Time.o