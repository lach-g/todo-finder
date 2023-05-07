P=todo_finder
CC= c99
CFLAGS=-Wall -g -O0
LDLIBS=

all: $(P)
$(P): $(P).o
$(P).o: $(P).c $(P).h

clean:
	rm -f $(P) $(P).o
run: $(P)
	./$(P)
