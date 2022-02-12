CC=g++
CFLAGS=-Og -g 
LIBS=-I.
all: out/main

out/main: out/main.o
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LIBS) -o $@ $^

out/%.o: %.cpp
	$(CC) $(CFLAGS) -c $(CPPFLAGS) -o $@ $^


.PHONY: clean
clean:
	rm -f out/*