default:	clean compile

clean:
	@rm -rf target *.o *.h.gch

compile:	node.h node.c target.c
	gcc -c node.c -o node.o
	gcc -c target.c -o target.o
	gcc node.o target.o -o target

test:			default
	./target
