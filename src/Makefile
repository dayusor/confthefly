CFLAGS=-Wall -Werror -g
CFILES=main.c linked_list.c hash_fun.c
GENERATED_FILES=`ls | egrep -v 'Makefile|*\.c|*\.h'`

all:
	gcc ${CFLAGS} ${CFILES} -o daemon

clean:
	@echo ${GENERATED_FILES} | xargs -I {} rm {}
	@echo "clean ok"
