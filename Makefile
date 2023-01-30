TARGETS = test

CFLAGS += -std=c99
CFLAGS += -g
CFLAGS += -Wall -l -L -pedantic -lm

all:: $(TARGETS)


test: tests.c decide.h LICs.c
	gcc tests.c decide.h LICs.c -lm


clean:
	rm -f *.o

