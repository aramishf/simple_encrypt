#include <stdio.h>

// one hex digit = 4 bits (nibble)
// 4 hex digits = 16 bits = 2 bytes

int main() {
  int N = 0x0001; // hexa-decimal value                                    //
                  // 16-bit key, inputed as hexadecimal value

  // open file for reading "r"
  FILE *file = fopen("input.txt", "r");

  // check if file is not empty
  if (file != NULL) {
    char *input[256];

    // read the input from the file
    fscanf(file, "%x", &input[256]);

    // close the file
    fclose(file);
  }

  // convert hexadecimal input to binary
}
