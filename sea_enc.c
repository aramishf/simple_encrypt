#include <stdio.h>
#include <stdlib.h> // for strtol()
#include <unistd.h> // for read()

// one hex digit = 4 bits (nibble)
// 4 hex digits = 16 bits = 2 bytes

// argc = argument count (# of arg passed in program)
// argv = argument vector
int main(int argc, char *argv[]) {
  // check for the 16-bit key argument
  // if no key provided, return -1
  if (argc < 2) {
    printf("Usage: ./sea_enc KEY_IN_HEX\n");
    return -1;
  }

  // convert key form hex to int
  // argv[1] - first arg passed to program
  int N = strtol(argv[1], NULL, 16);

  // Read input bytes from stdin one by one
}
