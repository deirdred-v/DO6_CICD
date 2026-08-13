#include <stdio.h>
#include <string.h>

int just_cat(char *f_name, char *flags);
void flags(char *flg, int argc, char **argv, int *eoflg);
void ex_flags(char *flg, char flag);
void a_flags(char *flags, char flag);
void printing(int a, int *prev, char *flags, int *index, int *el_printed);

int main(int argc, char **argv) {
  char flg[7] = "\0";
  int eoflg = 1;
  flags(flg, argc, argv, &eoflg);
  for (int i = 1; i < argc; i++) {
    just_cat(argv[i], flg);
  }
  return 0;
}

int just_cat(char *f_name, char *flg) {
  int err_code = 0;
  FILE *f = fopen(f_name, "rt");
  if (f != NULL) {
    int index = 0;
    int el_printed = 0;
    int a = fgetc(f), prev = '\n';
    while (a != EOF) {
      printing(a, &prev, flg, &index, &el_printed);
      a = fgetc(f);
    }
    fclose(f);
  } else {
    err_code = 1;
  }
  return err_code;
}

void flags(char *flg, int argc, char **argv, int *eoflg) {
  for (int i = 1; i < argc; i++) {
    if (argv[i][0] != '-' || strcmp(argv[i], "--") == 0 ||
        strcmp(argv[i], "-") == 0) {
      break;
    } else {
      *eoflg = i;
      for (size_t j = 1; j < strlen(argv[i]); j++) {
        ex_flags(flg, argv[i][j]);
      }
    }
  }
}

struct flagstruct {
  char flag;
  char *eq_flags;
};

void ex_flags(char *flg, char flag) {
  struct flagstruct flagstr[8] = {{'b', "b"},  {'E', "E"}, {'e', "Ev"},
                                  {'n', "n"},  {'s', "s"}, {'T', "T"},
                                  {'t', "Tv"}, {'v', "v"}};
  for (int i = 0; i < 8; i++) {
    if (flagstr[i].flag == flag) {
      for (size_t j = 0; j < strlen(flagstr[i].eq_flags); j++) {
        a_flags(flg, flagstr[i].eq_flags[j]);
      }
      break;
    }
  }
}

void a_flags(char *flags, char flag) {
  if (strchr(flags, flag) == NULL) {
    char temp[2] = "-";
    temp[0] = flag;
    strcat(flags, temp);
  }
}

void printing(int a, int *prev, char *flags, int *index, int *el_printed) {
  if (!(strchr(flags, 's') != NULL && *prev == '\n' && a == '\n' &&
        *el_printed)) {
    if (*prev == '\n' && a == '\n')
      *el_printed = 1;
    else
      *el_printed = 0;

    if (((strchr(flags, 'n') != NULL && strchr(flags, 'b') == NULL) ||
         (strchr(flags, 'b') != NULL && a != '\n')) &&
        *prev == '\n') {
      *index += 1;
      printf("%6d\t", *index);
    }

    if (strchr(flags, 'E') != NULL && a == '\n') printf("$");
    if (strchr(flags, 'T') != NULL && a == '\t') {
      printf("^");
      a = '\t' + 64;
    }
    if (strchr(flags, 'v') != NULL && a >= 0 && a <= 31 && a != '\n' &&
        a != '\t') {
      printf("^");
      a = a + 64;
    }
    fputc(a, stdout);
  }
  *prev = a;
}