#include <random.h>

unsigned int rseed;

void init_random() {
	srand(RAND_SEED);
	rseed = RAND_SEED;
}

unsigned short random_ushort() {
	return rand();
}

unsigned int random_uint(x) {
	return((RANDOM_A*x) + RANDOM_C);
}

float random_float(x) {
	return((float) random_uint(x));
}