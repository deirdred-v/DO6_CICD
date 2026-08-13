all: s21_grep

s21_grep: s21_grep.o
	gcc -std=c11 s21_grep.o -o s21_grep

s21_grep.o: s21_grep.c
	gcc -Wall -Werror -Wextra -c s21_grep.c

clean:
	rm -rf *.o