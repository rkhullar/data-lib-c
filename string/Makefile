CC      = gcc
CFLAGS  =
EXEC    = target
DEPS    = string.h
OBJS    = string.o target.o

default: clean compile

clean:
	@rm -rf $(EXEC) *.o *.h.gch

compile: $(OBJS)
	$(CC) $^ $(CFLAGS) -o $(EXEC)

test: default
	./$(EXEC)

%.o: %.c $(DEPS)
	$(CC) -c $< $(CFLAGS) -o $@
