all: fifth

fifth: fifth.c 
	gcc -g -Wall -Werror -fsanitize=address -std=c11 fifth.c -o fifth -lm

clean: 
	rm -rf fifth