#include <stdio.h>
#include <stdlib.h>

#define _CRT_SECURE_NO_DEPRECATE
#pragma warning (disable : 4996)

#define NUM_STUDENTS 4

struct student{
	char forename[128];
	char surname[128];
	float average_module_mark;

};

void print_student(const struct student *s);

void main(){
	struct student *students = (struct student *) malloc(sizeof(struct student) * NUM_STUDENTS);
	int i;

	FILE *f = NULL;
	f = fopen("students.bin", "rb"); //read and binary flags
	if (f == NULL){
		fprintf(stderr, "Error: Could not find students.bin file \n");
		exit(1);
	}

	fread(students, sizeof(struct student), NUM_STUDENTS, f);
	fclose(f);

	for (i = 0; i < NUM_STUDENTS; i++){
		print_student(&students[i]);

	}
	free(students);
}

void print_student(const struct student *s){
	printf("Student:\n");
	printf("\tForename: %s\n", s->forename);
	printf("\tSurname: %s\n", s->surname);
	printf("\tAverage Module Mark: %.2f\n", s->average_module_mark);
}

