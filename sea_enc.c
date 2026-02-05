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
    printf("USAGE: ./sea_enc KEY_IN_HEX\n");
    return 1;
  }

  // convert key form hex to int
  // argv[1] - first arg passed to program
  // unsigned short for easy bit manipulation
  unsigned short N = (unsigned short)strtol(argv[1], NULL, 16);

  // Read input bytes from stdin one by one
  unsigned char input_byte;
  int count = 0;

  // while loop to read bytes from stdin
  // read() returns number of bytes read
  // file descriptor 0 is stdin
  while (read(0, &input_byte, 1) > 0) {

    // XOR N with input byte and get lower 8 bits
    unsigned char encrypted = (N ^ input_byte) & 0xFF;

    // Output as two upper case hex char (%02x handles nibble encoding)
    printf("%02X", encrypted);
    count++;

    // newlien every 40 bytes
    if (count % 40 == 0) {
      printf("\n");
    }

    // rol 1 bit
    // for 16 bit: bit 15 moves to bit 0
    // bit 14 moves to bit 13, etc
    N = ((N << 1) | (N >> 15)) & 0xFFFF;

    // multiply by 257 and keep lower 16 bits
    N = (N * 257) & 0xFFFF;
  }

  // print newline after all bytes are encrypted
  // if no bytes encrypted OR if last line is not full
  if (count == 0 || count % 40 != 0) {
    printf("\n");
  }

  return 0;
}
