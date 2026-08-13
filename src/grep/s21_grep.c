#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int just_grep(char *f_name, char *flags, char **prompt, int e_count,
              int f_count);
void flags(char *flg, int argc, char **argv, int *eoflg);
void ex_flags(char *flg, char flag);
void a_flags(char *flags, char flag);
int printing(char *temp_str, char *flags, int *index, char **prompt,
             int e_count);

int main(int argc, char **argv) {
  char flg[7] = "\0";
  int eoflg = 1, e_count = 0, f_count = 0;
  flags(flg, argc, argv, &eoflg);
  for (int i = 1; i < argc; i++) {
    FILE *f = fopen(argv[i], "rt");
    if (f != NULL) {
      f_count++;
      fclose(f);
    }
  }
  char **prompt;
  prompt = (char **)malloc(1024 * sizeof(char *));
  for (int i = 0; i < 1024; i++) {
    prompt[i] = (char *)malloc(1024 * sizeof(char));
    for (int j = 0; j < 1024; j++) {
      prompt[i][j] = '\0';
    }
  }
  if (f_count != 0) {
    for (int i = 1; i < argc - f_count; i++) {
      size_t j = 0;
      if (strchr(argv[i], '-') == NULL) {
        for (j = 0; j != strlen(argv[i]); j++) {
          prompt[e_count][j] = argv[i][j];
        }
        prompt[e_count][j + 1] = '\0';
        e_count++;
        if ((strchr(argv[i + 1], '-') == NULL) || (strchr(flg, 'e') == NULL)) {
          i = argc;
        }
      }
    }
    if (e_count != 0) {
      for (int i = 1; i < argc; i++) {
        just_grep(argv[i], flg, prompt, e_count, f_count);
      }
    }
  } else {
    printf("No such file or directory\n");
  }
  for (int i = 0; i < 1024; i++) {
    free(prompt[i]);
  }
  free(prompt);
  return 0;
}

int just_grep(char *f_name, char *flg, char **prompt, int e_count,
              int f_count) {
  int err_code = 0;
  FILE *f = fopen(f_name, "rt");
  if (f != NULL && e_count != 0) {
    int same_str = 0;
    int index = 0;
    char *temp_str;
    temp_str = (char *)malloc(1024 * sizeof(char));
    while (fgets(temp_str, 1024, f) != NULL) {
      switch (printing(temp_str, flg, &index, prompt, e_count)) {
        case 0:

          if ((strchr(flg, 'l') != NULL) || (strchr(flg, 'c') != NULL)) {
            same_str++;
            if (same_str == 1 && f_count > 1) {
              printf("%s", f_name);
              if (strchr(flg, 'c') != NULL) {
                printf(":");
              }
            }
          } else {
            if (f_count > 1) {
              printf("%s:", f_name);
            }
            if (strchr(flg, 'n') != NULL) {
              printf("%d:", index);
            }
            printf("%s", temp_str);
          }
          break;
        case 1:
          break;
      }
    }
    if ((strchr(flg, 'c') != NULL) ||
        ((strchr(flg, 'c') != NULL) && (strchr(flg, 'l') != NULL))) {
      if ((same_str == 0) && f_count > 1) {
        printf("%s:", f_name);
      }
      printf("%d\n", same_str);
    }
    if ((strchr(flg, 'l') != NULL) && (strchr(flg, 'c') == NULL) &&
        same_str != 0) {
      printf("\n");
    }
    free(temp_str);
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
};

void ex_flags(char *flg, char flag) {
  struct flagstruct flagstr[6] = {{'e'}, {'i'}, {'v'}, {'c'}, {'l'}, {'n'}};
  for (int i = 0; i < 6; i++) {
    if (flagstr[i].flag == flag) {
      a_flags(flg, flag);
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

int printing(char *temp_str, char *flags, int *index, char **prompt,
             int e_count) {
  regex_t regex;
  int re;
  int ret_num = 1;
  if (strchr(flags, 'v') != NULL) {
    int checker = 0;
    for (int i = 0; i < e_count; i++) {
      if (strchr(flags, 'i') != NULL) {
        re = regcomp(&regex, prompt[i], REG_ICASE);
      } else {
        re = regcomp(&regex, prompt[i], 0);
      }
      re = regexec(&regex, temp_str, 0, NULL, 0);
      if (re == REG_NOMATCH) {
        checker++;
      }
    }
    if (checker == e_count) {
      ret_num = 0;
    }
  }
  if (strchr(flags, 'v') == NULL) {
    for (int i = 0; i < e_count; i++) {
      if (strchr(flags, 'i') != NULL) {
        re = regcomp(&regex, prompt[i], REG_ICASE);
      } else {
        re = regcomp(&regex, prompt[i], 0);
      }
      re = regexec(&regex, temp_str, 0, NULL, 0);
      if (!re) {
        ret_num = 0;
      }
    }
  }
  if (strchr(flags, 'n') != NULL) {
    *index += 1;
  }
  regfree(&regex);
  return ret_num;
}
