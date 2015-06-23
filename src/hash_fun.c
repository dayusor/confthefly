#include <stdio.h>

unsigned long
hash(unsigned char *str) {
    unsigned long hash = 0;
    int c;

    while ((c = *str++) != '\0') {
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
		printf("%ld\n", hash);
	}

    return hash % 100;
}

int
main (int argc, char *argv[]) {
	printf("hash_code of: %s %lu\n", argv[1], hash((unsigned char *)argv[1]));
	return 0;
}
