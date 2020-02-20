#include <stdio.h>
#include <stdlib.h>

typedef struct llitem{
	struct llitem *previous;
	struct llitem *next;
	void* record;
} llitem;

void (*print_callback)(void* r) = NULL;

void print_items(llitem *ll_start){
	llitem *ll = ll_start;
	while (ll != NULL){
		//printf
		if (print_callback != NULL)
			print_callback(ll->record);
		//next
		ll = ll->next;
	}
}

llitem* create_linked_list(){
	llitem* ll_start;

	ll_start = (llitem*)malloc(sizeof(llitem));
	ll_start->next = NULL;
	ll_start->previous = NULL;
	ll_start->record = NULL;
	return ll_start;
}

llitem* add_to_linked_list(llitem* ll_end){
	if (ll_end->next != NULL) {
		return NULL;
	}
	else {
		llitem* new_ll_end;
		new_ll_end = (llitem*)malloc(sizeof(llitem));
		new_ll_end->previous = ll_end;
		new_ll_end->next = NULL;
		new_ll_end->record = NULL;
		ll_end->next = new_ll_end;
		return new_ll_end;
	};
}

void free_linked_list(llitem *ll_start){
	llitem *ll = ll_start;
	while (ll != NULL){
		llitem *temp = ll->next;
		free(ll);
		ll = temp;
	}
}

