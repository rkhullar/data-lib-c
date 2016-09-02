CC      = gcc
IDIR    = /opt/lib
LDIR    = /opt/lib
EXEC    = target
DEPS    = node.h list.h macros.h
OBJS    = node.o list.o target.o
LIBS    = -lmisc -lstring
CFLAGS  = -I $(IDIR) -L $(LDIR)

default: clean compile

clean:
	@rm -rf $(EXEC) *.o *.h.gch

%.o: %.c $(DEPS)
	$(CC) -c $< $(CFLAGS) -o $@

compile: $(OBJS)
	$(CC) $^ $(CFLAGS) -o $(EXEC) $(LIBS)

manual:
	$(CC) -c target.c $(CFLAGS) -o target.o
	$(CC) -c node.c   $(CFLAGS) -o node.o
	$(CC) -c list.c   $(CFLAGS) -o list.o
	$(CC) $(OBJS) $(CFLAGS) -o $(EXEC) $(LIBS)

test: default
	./$(EXEC)
