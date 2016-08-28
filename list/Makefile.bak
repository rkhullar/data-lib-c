CC      = gcc
#CFLAGS  = -DT=int
CFLAGS  =
EXEC    = target
DEPS    = node.h list.h string.h misc.h macros.h
OBJS    = node.o list.o string.o misc.o target.o

default: clean compile

clean:
	@rm -rf $(EXEC) *.o *.h.gch

compile: $(OBJS)
	$(CC) $^ $(CFLAGS) -o $(EXEC)

test: default
	./$(EXEC)

%.o: %.c $(DEPS)
	$(CC) -c $< $(CFLAGS) -o $@
