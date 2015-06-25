#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"
#include "hash_fun.h"
#include "hash_table.h"

hash_table_t *
create_ht(int size) {
	hash_table_t *ht = malloc(sizeof(hash_table_t));
	ht->size = size;
	ht->parent_node = malloc(sizeof(root_list_node)*size);
	int node = 0;
	while (node < size) {
		ht->parent_node[node] = NULL;
		++node;
	}
	return ht;
}

void
insert_node_ht(hash_table_t *ht, const char *string) {

	unsigned long hash_index = hash_dbj2((unsigned char *)string);

	if (ht->parent_node[hash_index] == NULL) {
		ht->parent_node[hash_index] = new_root_list_node(string);
	}
	else {
		create_and_append(ht->parent_node[hash_index], string);
	}
}

void
free_ht(hash_table_t *ht, int size) {
	int i;
	for (i = 0; i < size; i++) {
		free_list_memory(ht->parent_node[i]);
	}
	free(ht->parent_node);
	free(ht);
}

int main() {

	// LOOK FOR 10 with git grep to replace for a fixed value
	hash_table_t *ht = create_ht(10);
	insert_node_ht(ht, "foo"); // hash_dbj2("foo") = 2
	insert_node_ht(ht, "bar"); // hash_dbj2("bar") = 7
	insert_node_ht(ht, "bazz"); // hash_dbj2("bazz") = 7

	// TESTS
	printf("%s\n", ht->parent_node[2]->string);
	printf("%s\n", ht->parent_node[7]->string);
	printf("%s\n", ht->parent_node[7]->next->string);
	free_ht(ht, 10);
	// END TESTS
	return 0;
}

/*
hash_table_t *
search_string(hash_table_t *ht, char *str) {

}
*/
