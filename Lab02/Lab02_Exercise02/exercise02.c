#include <stdio.h>
#include <stdlib.h>

#define _CRT_SECURE_NO_DEPRECATE
#pragma warning (disable : 4996)

#define NUM_STUDENTS 4

struct student{
	unsigned int n;
	char *forename;//[128]
	unsigned int m;
	char *surname;
	float average_module_mark;
};

void print_student(const struct student *s);

void main(){
	struct student *students = (struct student *) malloc(sizeof(struct student) * NUM_STUDENTS);
	int i;

	FILE *f = NULL;
	f = fopen("students2.bin", "rb"); //read and binary flags
	if (f == NULL){
		fprintf(stderr, "Error: Could not find students2.bin file \n");
		exit(1);
	}

	//fread(students, sizeof(struct student), NUM_STUDENTS, f);
	//fclose(f);

	for (i = 0; i < NUM_STUDENTS; i++){
		unsigned int *n;////////////////////////
		unsigned int *m;
		fread(n, sizeof(&n), 1, f);
		fread(students, sizeof(char) * n, 1, f);
		fread(m, sizeof(&n), 1, f);
		fread(students, sizeof(char) * m, 1, f);
		fread(students, sizeof(float), 1, f);//////////////////


		print_student(&students[i]);

	}

	fclose(f);///////

	free(students);
}

void print_student(const struct student *s){
	printf("Student:\n");
	printf("\tForename: %s\n", s->forename);
	printf("\tSurname: %s\n", s->surname);
	printf("\tAverage Module Mark: %.2f\n", s->average_module_mark);
}

