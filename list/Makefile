EXEC    = target
CFLAGS  = -DT=int

default:	clean compile

clean:
	@rm -rf $(EXEC) *.o *.h.gch

compile:	node.h node.c list.h list.c $(EXEC).c
	gcc -c $(CFLAGS) node.c -o node.o
	gcc -c $(CFLAGS) list.c -o list.o
	gcc -c $(CFLAGS) $(EXEC).c -o $(EXEC).o
	gcc node.o list.o $(EXEC).o -o $(EXEC)

test:			default
	./$(EXEC)
