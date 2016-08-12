EXEC    = target
SUPPORT = object

default:	clean compile

clean:
	@rm -rf $(EXEC) *.o *.h.gch

compile:	$(SUPPORT).h $(SUPPORT).c $(EXEC).c
	gcc -c $(SUPPORT).c -o $(SUPPORT).o
	gcc -c $(EXEC).c -o $(EXEC).o
	gcc $(SUPPORT).o $(EXEC).o -o $(EXEC)

test:			default
	./$(EXEC)
