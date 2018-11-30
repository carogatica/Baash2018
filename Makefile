CC = gcc
CFLAGS = -Wall -pedantic-errors
SRC = baash.c entrada.c salida.c pipe.c segundoPlano.c
OBJ = baash.o 

all: $(OBJ)
	$(CC) $(CFLAGS) $(SRC) -o baash 

clean:
	$(RM) $(OBJ) baash