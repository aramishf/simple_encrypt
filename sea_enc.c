/*
 * sea_enc.c
 * Simple Encryption Algorithm Encoder
 *
 * Usage: ./sea_enc KEY_IN_HEX
 * Reads from stdin, outputs hex-encoded encrypted bytes to stdout.
 */

#include <stdio.h>
#include <stdlib.h> // For strtol
#include <unistd.h> // For read

int main(int argc, char *argv[]) {
  // 1. Check for the 16-bit key argument
  // If no key is provided, print the usage message and exit with code 1
  if (argc < 2) {
    printf("USAGE: ./sea_enc KEY_IN_HEX\n");
    return 1;
  }

  // 2. Convert the key from hex string to integer
  // "The key should be interpreted as a hexadecimal number"
  unsigned short N = (unsigned short)strtol(argv[1], NULL, 16);

  unsigned char buffer;
  int bytes_read;
  int byte_count = 0;

  // 3. Read input bytes from standard input one by one
  while ((bytes_read = read(0, &buffer, 1)) > 0) {

    // --- XOR Step ---
    // "XOR the current value of N with the input byte"
    // "Output the lower 8 bits of the result"
    unsigned char result = (N ^ buffer);

    // Output as two uppercase hexadecimal characters (Nibble encoded)
    printf("%02X", result);

    // --- Update Step ---
    // "Rotate N to the left by 1 bit"
    // (High bit wraps around to become the low bit)
    unsigned short rotated_N = (N << 1) | (N >> 15);

    // "Multiply N by 257 (keeping only the lower 16 bits)"
    N = rotated_N * 257;

    byte_count++;

    // "A newline character... After every 40 encrypted bytes"
    if (byte_count % 40 == 0) {
      printf("\n");
    }
  }

  // "A newline character... After the last byte (the output always ends with a
  // newline)" "If the input is empty, output only a newline."
  printf("\n");

  return 0;
}