TARGETS = DECIDE test

CFLAGS += -std=c99
CFLAGS += -g -lstdc++
CFLAGS += -Wall -l -L -pedantic -lm

all:: $(TARGETS)

DECIDE: launch.c decide.h LICs.c CMV.c FUV.c PUM.c 
	gcc launch.c decide.h LICs.c CMV.c FUV.c PUM.c 
test: tests.c decide.h LICs.c
	gcc tests.c decide.h LICs.c -lm


clean:
	rm -f *.o

