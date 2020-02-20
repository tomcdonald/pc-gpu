#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

#define _CRT_SECURE_NO_DEPRECATE
#pragma warning (disable : 4996)

struct student{
	unsigned int n;
	char *forename;
	unsigned int m;
	char *surname;
	float average_module_mark;
};

void print_student(const struct student *s);

void main(){
	FILE *f = NULL;
	f = fopen("students2.bin", "rb"); //read and binary flags
	if (f == NULL){
		fprintf(stderr, "Error: Could not find students2.bin file \n");
		exit(1);
	}
	
	// Create linked list
	llitem *ll_start = NULL;
	llitem *ll_end = NULL;
	struct student *stud;

	// Set printing function
	print_callback = (void(*)(void *))&print_student;

	while (1) {
		stud = malloc(sizeof(struct student));
		// Reading forename
		unsigned int n;
		size_t ret = fread(&n, sizeof(unsigned int), 1, f);
		// Check for EOF
		if (ret != 1) {
			break;
		}
		// Finish forename storage
		stud->forename = malloc(sizeof(char) * n);
		fread(stud->forename, sizeof(char) * n, 1, f);
		// Reading surname
		unsigned int m;
		fread(&m, sizeof(unsigned int), 1, f);
		stud->surname = malloc(sizeof(char) * m);
		fread(stud->surname, sizeof(char) * m, 1, f);
		// Reading module mark
		fread(&stud->average_module_mark, sizeof(float), 1, f);
		// Create linked list if doesn't exist, otherwise add to end
		if (ll_start == NULL) {
			ll_end = create_linked_list();
			ll_start = ll_end;
		}
		else {
			ll_end = add_to_linked_list(ll_end);
		}
		// Assign record to new node
		ll_end->record = stud;
	}

	fclose(f);
	print_items(ll_start);

	// Free struct memory
	llitem *node = ll_start;
	while (node != NULL) {
		free(((struct student *)node->record)->surname);
		free(((struct student *)node->record)->forename);
		free((struct student *)node->record);
		node = node->next;
	}

	// Free linked list memory
	free_linked_list(ll_start);
}

void print_student(const struct student *s){
	printf("Student:\n");
	printf("\tForename: %s\n", s->forename);
	printf("\tSurname: %s\n", s->surname);
	printf("\tAverage Module Mark: %.2f\n", s->average_module_mark);
}

