
make:
	gcc -std=c11 homeExam.c -o homeExam
memcheck:
	-valgrind --leak-check=yes ./homeExam 1.txt
errorcheck:
	gcc -Wall -Werror -std=c11 homeExam.c -o homeExam
run:
	./homeExam 1.txt
clean:
	rm homeExam
code:
	vim homeExam.c
