data-structures: test/simplecircularlist_test.c
	gcc -c test/test.c
	gcc -c src/simplecircularlist.c
	gcc -o simplecircularlist test.o simplecircularlist.o
