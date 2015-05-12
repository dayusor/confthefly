#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked_list.h"

root_list_node *
new_root_list_node(const char *string) {
	root_list_node *root_node = malloc(sizeof(root_list_node));
	root_node->string = strdup(string);
	root_node->next = NULL;
	root_node->last = NULL;
	return root_node;
}

list_node *
new_list_node(const char *string) {
	list_node *list = malloc(sizeof(list_node));
	list->string = strdup(string);
	list->next = NULL;
	return list;
}

list_node *
create_and_append(root_list_node *root_node, const char *string) {
	list_node *new_node = new_list_node(string);
	if (root_node->next == NULL) {
		root_node->next = new_node;
	}
	else {
		list_node *node = root_node->last;
		node->next = new_node;
	}
	root_node->last = new_node;
	return root_node->last;
}

void
free_list_memory(root_list_node *root_node) {

	list_node *node = root_node->next;
	while (node->next != NULL) {
		list_node *next_node = node->next;
		free(node->string);
		free(node);
		node = next_node;
	}
	free(node->string);
	free(node);
	free(root_node->string);
	free(root_node);
}

list_node *
search_node_by_string(root_list_node *root_node, const char *string) {

	if (!strcmp(root_node->string, string))
		return (list_node *)root_node;

	list_node *node = root_node->next;

	while (node != NULL) {
		if (!strcmp(node->string, string)) {
			return node;
		}

		if (node->next == NULL) {
			printf("String not found in the list: NULL\n");
			printf("sub->string = %s, string = %s\n", node->string, string);
			return NULL;
		}

		node = node->next;
	}

	return 0;
}
