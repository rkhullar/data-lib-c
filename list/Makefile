CC      = gcc
CFLAGS  = -I /opt/lib # -Wall
EXEC    = target
DEPS    = node.h list.h string.h misc.h macros.h
OBJS    = node.o list.o string.o misc.o target.o

default: clean compile

clean:
	@rm -rf $(EXEC) *.o *.h.gch

compile:
	$(CC) -c target.c $(CFLAGS) -o target.o
	$(CC) -c node.c $(CFLAGS) -o node.o
	$(CC) -c list.c $(CFLAGS) -o list.o
	$(CC) -c ../string/string.c $(CFLAGS) -o string.o
	$(CC) -c ../misc/misc.c $(CFLAGS) -o misc.o
	$(CC) $(OBJS) $(CFLAGS) -o $(EXEC)

test: default
	./$(EXEC)
