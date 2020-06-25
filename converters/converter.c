#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <ctype.h>

const int MAX_DIGITS = 32;

int isBinary(const char *input);
int isNumber(const char *input);
void binaryToDecimal(int bin);
void decimalToBinary(int dec);

int main(int argc, char* args[]) {
  const char* filename = args[0];
  int opt;

  while ((opt = getopt(argc, args, "b:d:")) != -1) {
    switch(opt) {
      case 'd':
        if(isBinary(optarg)) {
          binaryToDecimal(atoi(optarg));
          printf("\n");
        } else {
          printf("Not a binary number.\n");
        }
        break;
      case 'b':
        if (isNumber(optarg)) {
          decimalToBinary(atoi(optarg));
          printf("\n");
        } else {
          printf("Not a decimal number.\n");
        }
        break;
    }
  }

  argc -= optind;
  args += optind;

  if (argc) {
      printf("Usage: %s -b [number] to convert decimal number to binary.\n %s -d [number] to convert binary number to decimal.\n",filename,filename);
  }

  return 0;
}

int isBinary(const char *input) {
    for (int i = 0; input[i]; i++)
        if (input[i] != '0' && input[i] != '1')
            return 0;
    return 1;
}

int isNumber(const char *input) {
  for (int i = 0; input[i]; i++)
      if (!isdigit(input[i]))
          return 0;
  return 1;
}

void binaryToDecimal(int bin) {
  int dec = 0, i = 0;

  while (bin != 0) {
    dec += bin % 10 * pow(2,i);
    bin /= 10;
    i++;
  }

  printf("%i",dec);
}

void decimalToBinary(int dec) {
  int i;
  int bin[MAX_DIGITS];
  for (i = 0; dec > 0; i++) {
    bin[i] = dec % 2;
    dec = dec/2;
  }

  for (i = i - 1; i >= 0; i--) {
    printf("%i",bin[i]);
  }
}
