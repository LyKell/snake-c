# Auteurs : Kevin SAVANE et Tom REDON
# Creation : 19-02-2019
# Modification : 03-03-2019

# Definition des constantes
CC = gcc
CFLAGS = -ansi -Wall
EXEC = Snake
LDFLAGS = -lm -lMLV
OBJ = Main.o IGraph.o Monde.o Pomme.o Serpent.o

# Definition des commandes a effectuer
Snake : $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

Main.o : Main.c Monde.h IGraph.h

IGraph.o : IGraph.c IGraph.h Monde.h

Monde.o : Monde.c Monde.h Pomme.h Serpent.h

Pomme.o : Pomme.c Pomme.h Serpent.h

Serpent.o : Serpent.c Serpent.h

%.o : %.c
	$(CC) -c $< $(CFLAGS) $(LDFLAGS)


# Definition des commandes de nettoyage
clean :
	rm -f *.o

mrproper : clean
	rm -f $(EXEC)


# Definition des commandes a appeler
install : $(EXEC)
	mkdir ../bin
	mv $(EXEC) ../bin/$(EXEC)
	make mrproper

uninstall : mrproper
	rm -f ../bin/$(EXEC)
	rm -rf ../bin
