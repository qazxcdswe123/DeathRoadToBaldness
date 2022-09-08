CC := clang
CXX := clang++
CFLAGS := -g -Wall
CXXFLAGS := -g -Wall

objects := ch2/linearList.o ycymain.o

all : $(objects)
	$(CXX) $(CXXFLAGS) -o main $(objects)

linearList.o : ch2/linearList.cpp 
ycymain.o : ycymain.cpp

.PHONY : clean
clean :
	-rm  main *.o