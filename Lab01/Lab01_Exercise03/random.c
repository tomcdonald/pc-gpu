#include <random.h>

unsigned int rseed;

void init_random() {
	srand(RAND_SEED);
	rseed = RAND_SEED;
}

unsigned short random_ushort() {
	return rand();
}

unsigned int random_uint(int n) {
	unsigned int rand_val = rseed;
	for (int j = 0; j < n + 1; j++) {
		rand_val = (RANDOM_A*rand_val) + RANDOM_C;
	}
	return(rand_val);
}

float random_float(int n) {
	return((float) random_uint(n));
}