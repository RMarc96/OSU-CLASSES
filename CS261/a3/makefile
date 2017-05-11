default: testcdll datime dlltime testdll

cirListDeque.o: cirListDeque.c cirListDeque.h
	gcc -Wall -g -std=c99 -c cirListDeque.c	

testCirListDeque.o: cirListDeque.h testCirListDeque.c
	gcc -Wall -g -std=c99 -c testCirListDeque.c

testcdll: cirListDeque.o testCirListDeque.o
	gcc -Wall -g -std=c99 -o testcdll cirListDeque.o testCirListDeque.o

datime:
	gcc -Wall -g -std=c99 -o datime dynamicArray.c dynamicArrayMain.c

dlltime:
	gcc -Wall -g -std=c99 -o dlltime linkedList.c linkedListMain.c

testdll:
	gcc -Wall -g -std=c99 -o testdll linkedList.c testLinkedList.c

clean:
	rm cirListDeque.o
	rm testCirListDeque.o
	rm testcdll
	rm datime
	rm dlltime
	rm testdll
