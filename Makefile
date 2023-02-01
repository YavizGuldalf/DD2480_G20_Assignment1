TARGETS = DECIDE test test_program

CFLAGS += -std=c99
CFLAGS += -g -lstdc++
CFLAGS += -lm
CFLAGS += -I./headers



all:: $(TARGETS)

DECIDE: launch.c headers/decide.h intermediate_results/LICs.c intermediate_results/CMV.c intermediate_results/FUV.c intermediate_results/PUM.c intermediate_results/DECIDE.c
	gcc launch.c headers/decide.h intermediate_results/LICs.c intermediate_results/CMV.c intermediate_results/FUV.c intermediate_results/PUM.c  intermediate_results/DECIDE.c -o DECIDE $(CFLAGS)

test: tests/lic_tests.c headers/decide.h intermediate_results/LICs.c
	gcc tests/lic_tests.c headers/decide.h intermediate_results/LICs.c -o lic_tests $(CFLAGS)
	
test_program: tests/test_program.c headers/decide.h intermediate_results/LICs.c intermediate_results/CMV.c intermediate_results/FUV.c intermediate_results/PUM.c intermediate_results/DECIDE.c
	gcc tests/test_program.c headers/decide.h intermediate_results/LICs.c intermediate_results/CMV.c intermediate_results/FUV.c intermediate_results/PUM.c intermediate_results/DECIDE.c -o test_program $(CFLAGS)

clean:
	rm -f *.o

