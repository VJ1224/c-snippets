#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void removeNewLine(char *ptr);

int main(int argc, char* args[]) {
  const int MAX_STR = 100;
  int column_length = 0;
  char delim[] = ",";
  char *ptr;
  char lines[MAX_STR];

  FILE *in;
  FILE *out;

  if (!args[1]) {
    printf("Usage: %s filename\n",args[0]);
    return 1;
  }

  ptr = strrchr(args[1], '.');
  if (ptr == NULL | strcmp(ptr, ".csv") != 0) {
    printf("Error: not a .csv file.\n");
    return 1;
  }

  in = fopen(args[1],"r");

  if (in == NULL) {
    printf("Error: file does not exist.\n");
    return 1;
  }

  out = fopen("data.json","w");
  fgets(lines, MAX_STR, in);

  int i = 0;
  char c ='a';

  while(c != '\n') {
    c = lines[i];
    if (c == ',')
      column_length++;
    i++;
  }

  column_length++;
  char keys[column_length][MAX_STR];

  i = 0;
  ptr = strtok(lines,delim);

  while (ptr != NULL) {
    removeNewLine(ptr);
    strcpy(keys[i], ptr);
    ptr = strtok(NULL,delim);
    i++;
  }

  i = 1;
  fprintf(out,"[\n");

  while(fgets(lines, MAX_STR, in)) {
      if (i != 1)
        fprintf(out,",\n");
      else
        i = 0;

      fprintf(out,"{\n");
      ptr = strtok(lines, delim);
      i = 0;

    	while(ptr != NULL) {
        removeNewLine(ptr);
        fprintf(out,"\t\"%s\" : \"%s\"", keys[i], ptr);

        if (i != column_length - 1)
          fprintf(out,",");

        fprintf(out,"\n");
        ptr = strtok(NULL, delim);
        i++;
    	}

      fprintf(out,"}");
  }

  fprintf(out,"]");
  fclose(in);
  fclose(out);

  return 0;
}

void removeNewLine(char *ptr) {
    if (ptr[strlen(ptr)-1] == '\n') {
      ptr[strlen(ptr)-1] = 0;
    }
}
