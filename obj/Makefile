CC = g++
OBJ = $(wildcard *.o)
TOBJ = $(wildcard *.t)
EXE = $(patsubst %.x, ../%.x, $(wildcard *.x))
gtkmmLIB = $(shell pkg-config gtkmm-3.0 --libs)
sfmlLIB = $(shell pkg-config sfml-audio --libs)
sfmlLIB += $(shell pkg-config sfml-graphics --libs)
cvLIB = $(shell pkg-config opencv --libs)

all : $(EXE)

../%.x : %.x $(OBJ)
	$(CC) -o $@ $< $(OBJ) -lstdc++fs -lpthread $(sfmlLIB) -lnettle -lhogweed

../%.x : %.tx $(OBJ) $(TOBJ)
	$(CC) -o $@ $< $(OBJ) $(TOBJ) -lstdc++fs -lpthread $(sfmlLIB)

