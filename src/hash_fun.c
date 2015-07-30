#include <stdio.h>

unsigned long
hash_dbj2(unsigned char *str) {
    unsigned long hash = 0;
    int c;

    while ((c = *str++) != '\0') {
        hash = ((hash << 5) + hash) + c;
	}

	unsigned long array_index = hash % 10;

    return array_index;
}
