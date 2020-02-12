#include <stdio.h>
#include <stdlib.h>
#include <random.h>

// Define new array
#define NUM_VALUES 250
signed long long value[NUM_VALUES];

int main()
{
	// Define positive integer counters and call header
	unsigned long long sum = 0;
	unsigned int i = 0;
	init_random();
	// Add random values to array
	signed long long x = RAND_SEED;
	for (i; i < NUM_VALUES; i++)
	{
		value[i] = (unsigned int)random_uint(x);
		//printf("i = %d, value stored = %d\n", i, value[i]);
		sum += value[i];
		x = value[i];
	}
	// Output sum and compute average
	//printf("Sum of values = %d\n", sum);
	signed long long average = sum / NUM_VALUES;
	// Normalise array
	signed long long min = value[0] - average;
	signed long max = value[0] - average;
	for (i = 1; i < NUM_VALUES; i++)
	{
		value[i] -= average;
		signed long long new_val = value[i];
		min = (new_val < min) ? new_val : min;
		max = (new_val > max) ? new_val : max;
	}
	// Output summary
	printf("Sum = %lld, Average = %lld, Min = %lld, Max = %ld\n", sum, average, min, max);
	return 0;
}