/* list node and root node are a little different
 * because the root node have a pointer to the last node
 * for performance reasons
 */

typedef struct list_node {
	char *string;
	struct list_node *next;
} list_node;

typedef struct root_node {
	char *string;
	struct list_node *next;
	struct list_node *last;
} root_node;

list_node * new_list_node(const char *string);

list_node * create_and_append(list_node *final_node, const char *string);

void free_list_memory(list_node *root_node);

list_node * search_node_by_string(list_node *root_node, const char *string);
