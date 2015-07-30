#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked_list.h"

int main() {
	// create root list node with the string yolo
	root_list_node *root_list = new_root_list_node("yolo");

	int i;
	// populate a list with 0 to 10
	for (i = 0; i <= 10; i++ ) {
		char *string = malloc(sizeof(char) * 10);
		snprintf(string, sizeof(char) * 10, "%d", i);
		create_and_append(root_list, string);
		free(string);
	}

	// search the node with the string 10
	list_node *match_node = search_node_by_string(root_list, "10");
	if (match_node)
		printf("String found in the list: %s\n", match_node->string);

	// free memory
	free_list_memory(root_list);
	return 0;
}
/*

int
main (int argc, char *argv[]) {
	printf("hash_code of: %s %lu\n", argv[1], hash((unsigned char *)argv[1]));
	return 0;
}
*/
