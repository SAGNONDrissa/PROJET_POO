
CC = g++
EXEC = prog
SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)

all : $(EXEC)

%.o : %.cpp
	$(CC) -o $@ -c $<   
	
$(EXEC) : $(OBJ)
	$(CC) -o $@ $^ ;


	


