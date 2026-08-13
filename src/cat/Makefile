all: s21_cat

s21_cat: s21_cat.o
	gcc -std=c11 s21_cat.o -o s21_cat

s21_cat.o: s21_cat.c
	gcc -Wall -Werror -Wextra -c s21_cat.c

clean:
	rm -rf *.o