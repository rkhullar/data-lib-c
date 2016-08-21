CC      = gcc
CFLAGS  =
EXEC    = target
DEPS    = string.h misc.h
OBJS    = string.o misc.o target.o

default: clean compile

clean:
	@rm -rf $(EXEC) *.o *.h.gch

compile: $(OBJS)
	$(CC) $^ $(CFLAGS) -o $(EXEC)

test: default
	./$(EXEC)

%.o: %.c $(DEPS)
	$(CC) -c $< $(CFLAGS) -o $@
