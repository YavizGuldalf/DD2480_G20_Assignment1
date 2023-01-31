TARGETS = DECIDE test

CFLAGS += -std=c99
CFLAGS += -g -lstdc++
CFLAGS += -Wall -pedantic -lm
CFLAGS += -I./headers



all:: $(TARGETS)

DECIDE: launch.c headers/decide.h intermediate_results/LICs.c intermediate_results/CMV.c intermediate_results/FUV.c intermediate_results/PUM.c 
	gcc launch.c headers/decide.h intermediate_results/LICs.c intermediate_results/CMV.c intermediate_results/FUV.c intermediate_results/PUM.c  \
	-o DECIDE $(CFLAGS)
test: tests/lic_tests.c headers/decide.h intermediate_results/LICs.c
	gcc tests/lic_tests.c headers/decide.h intermediate_results/LICs.c -o lic_tests $(CFLAGS)



clean:
	rm -f *.o

