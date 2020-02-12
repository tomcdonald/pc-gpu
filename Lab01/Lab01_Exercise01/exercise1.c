#include <stdio.h>
#include <random.h>

// Define new array
#define NUM_VALUES 250
int value[NUM_VALUES];

int main()
{
	// Define positive integer counters and call header
	unsigned int sum = 0;
	unsigned int i = 0;
	init_random();
	// Add random values to array
	for (i; i < NUM_VALUES; i++)
	{
		value[i] = (unsigned short) random_ushort();
		//printf("i = %d, value stored = %d\n", i, value[i]);
		sum += value[i];
	}
	// Output sum and compute average
	//printf("Sum of values = %d\n", sum);
	int average = sum / NUM_VALUES;
	// Normalise array
	int min = 9999999;
	int max = 0;
	for (i = 0; i < NUM_VALUES; i++)
	{
		value[i] -= average;
		min = (value[i] < min) ? value[i] : min ;
		max = (value[i] > max) ? value[i] : max ;
	}
	// Output summary
	printf("Sum = %d, Average = %d, Min = %d, Max = %d\n", sum, average, min, max);
	return 0;
}