#include <stdio.h>
#include <stdlib.h>

#define _CRT_SECURE_NO_DEPRECATE
#pragma warning (disable : 4996)

#define NUM_STUDENTS 4

struct student{
	unsigned int n;
	char *forename;
	unsigned int m;
	char *surname;
	float average_module_mark;
};

void print_student(const struct student *s);

void main(){
	struct student *students = (struct student *) malloc(sizeof(struct student) * NUM_STUDENTS);
	//struct student *students;
	int i;

	FILE *f = NULL;
	f = fopen("students2.bin", "rb"); //read and binary flags
	if (f == NULL){
		fprintf(stderr, "Error: Could not find students2.bin file \n");
		exit(1);
	}

	for (i = 0; i < NUM_STUDENTS; i++){
		// Reading forename
		unsigned int n;
		fread(&n, sizeof(unsigned int), 1, f);
		students[i].forename = malloc(sizeof(char) * n);
		fread(students[i].forename, sizeof(char) * n, 1, f);
		// Reading surname
		unsigned int m;
		fread(&m, sizeof(unsigned int), 1, f);
		students[i].surname = malloc(sizeof(char) * m);
		fread(students[i].surname, sizeof(char) * m, 1, f);
		// Reading module mark
		fread(&students[i].average_module_mark, sizeof(float), 1, f);

		print_student(&students[i]);
	}

	fclose(f);
	free(students);
}

void print_student(const struct student *s){
	printf("Student:\n");
	printf("\tForename: %s\n", s->forename);
	printf("\tSurname: %s\n", s->surname);
	printf("\tAverage Module Mark: %.2f\n", s->average_module_mark);
}

