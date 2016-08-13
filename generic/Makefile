EXEC    = target
SUPPORT = generic
CFLAGS  = -DT=int

default:	clean compile

clean:
	@rm -rf $(EXEC) *.o *.h.gch

compile:	$(SUPPORT).h $(SUPPORT).c $(EXEC).c
	gcc -c $(CFLAGS) $(SUPPORT).c -o $(SUPPORT).o
	gcc -c $(CFLAGS) $(EXEC).c -o $(EXEC).o
	gcc $(SUPPORT).o $(EXEC).o -o $(EXEC)

test:			default
	./$(EXEC)
