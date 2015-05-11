#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked_list.h"

int main() {
	list_node *list = new_list_node("yolo");
	list_node *final_node = list;

	int i;
	for (i = 0; i <= 1000000; i++ ) {
		char *string = malloc(sizeof(char) * 10);
		snprintf(string, sizeof(char) * 10, "%d", i);
		final_node = create_and_append(final_node, string);
	}

	list_node *match_node = search_node_by_string(list, "1000000");
	if (match_node)
		printf("String found in the list: %s\n", match_node->string);

	free_list_memory(list);
	return 0;
}

