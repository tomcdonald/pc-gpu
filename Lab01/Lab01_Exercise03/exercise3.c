#include <stdio.h>
#include <stdlib.h>
#include <random.h>

// Define new array
#define NUM_VALUES 250
float value[NUM_VALUES];

int main()
{
	// Define positive integer counters and call header
	float sum = 0;
	unsigned int i = 0;
	init_random();
	// Add random values to array
	float x = (float) RAND_SEED;
	for (i; i < NUM_VALUES; i++)
	{
		value[i] = random_float(x);
		printf("i = %d, value stored = %0.f\n", i, value[i]);
		sum += value[i];
		x = value[i];
	}
	// Output sum and compute average
	//printf("Sum of values = %d\n", sum);
	float average = sum / NUM_VALUES;
	// Normalise array
	float min = value[0] - average;
	float max = value[0] - average;
	for (i = 1; i < NUM_VALUES; i++)
	{
		value[i] -= average;
		float new_val = value[i];
		min = (new_val < min) ? new_val : min;
		max = (new_val > max) ? new_val : max;
	}
	// Output summary
	printf("Sum = %.0f, Average = %.0f, Min = %.0f, Max = %.0f\n", sum, average, min, max);
	return 0;
}