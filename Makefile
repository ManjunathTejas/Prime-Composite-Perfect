#Makefile for parfait.c with macros

FLAGS	=-std=c99 -Wall
SOURCES	= bv.c sieve.c parfait.c
OBJECTS	= bv.o sieve.o parfait.o
EXEBIN	= parfait

all: $(EXEBIN)

$(EXEBIN) : $(OBJECTS)
	gcc -o $(EXEBIN) $(OBJECTS) -lm

$(OBJECTS) : $(SOURCES)
	gcc -c $(FLAGS) $(SOURCES)

clean :
	rm -f $(EXEBIN) $(OBJECTS)
