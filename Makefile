TARGETS = DECIDE test

CFLAGS += -std=c99
CFLAGS += -g -lstdc++
CFLAGS += -Wall -pedantic -lm

all:: $(TARGETS)

DECIDE: launch.c decide.h LICs.c CMV.c FUV.c PUM.c 
	gcc launch.c decide.h LICs.c CMV.c FUV.c PUM.c -o launch $(CFLAGS)
test: tests.c decide.h LICs.c
	gcc tests.c decide.h LICs.c -o test $(CFLAGS)


clean:
	rm -f *.o

