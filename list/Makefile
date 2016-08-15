CC      = gcc
CFLAGS  = -DT=int
EXEC    = target
DEPS    = node.h list.h misc.h
OBJS    = node.o list.o misc.o target.o

default: clean compile

clean:
	@rm -rf $(EXEC) *.o *.h.gch

compile: $(OBJS)
	$(CC) $^ $(CFLAGS) -o $(EXEC)

test: default
	./$(EXEC)

%.o: %.c $(DEPS)
	$(CC) -c $< $(CFLAGS) -o $@
