#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked_list.h"

list_node *
new_list_node(const char *string) {
	list_node *list = malloc(sizeof(list_node));
	list->string = strdup(string);
	list->next = NULL;
	return list;
}

list_node *
create_and_append(list_node *final_node, const char *string) {
	final_node->next = new_list_node(string);
	return final_node->next;
}

void
free_list_memory(list_node *root_node) {
	list_node *node = root_node;
	while (node->next) {
		list_node *next_node = node->next;
		free(node->string);
		free(node);
		node = next_node;
	}
	free(node->string);
	free(node->next);
	free(node);
}

list_node *
search_node_by_string(list_node *root_node, const char *string) {

	list_node *sublist = root_node;
	while (sublist != NULL) {

		if (!strcmp(sublist->string, string)) {
			return sublist;
		}

		if (sublist->next == NULL) {
			printf("String not found in the list: NULL\n");
			printf("sub->string = %s, string = %s\n", sublist->string, string);
			return NULL;
		}
		sublist = sublist->next;
	}
	return 0;
}
