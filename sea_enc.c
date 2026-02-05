#include <stdio.h>
#include <stdlib.h> // For strtol
#include <unistd.h> // For read

int main(int argc, char *argv[]) {
  // 1. Check for the key (Usage check)
  if (argc < 2) {
    printf("USAGE: ./sea_enc KEY_IN_HEX\n");
    return 1;
  }

  // 2. Convert the key using strtol (Requirement)
  // base 16 tells it to look for hex
  unsigned short N = (unsigned short)strtol(argv[1], NULL, 16);

  unsigned char buffer;
  int bytes_read;
  int byte_count = 0;

  // 3. Read from STDIN (0) one byte at a time (Requirement)
  while ((bytes_read = read(0, &buffer, 1)) > 0) {

    // --- YOUR ALGORITHM GOES HERE ---
    // 1. XOR: (N ^ buffer) & 0xFF
    // 2. Output: printf("%02X", result)
    // 3. Update N: Rotate Left, then Multiply by 257

    byte_count++;

    // Handle the 40-byte newline rule
    if (byte_count % 40 == 0) {
      printf("\n");
    }
  }

  // 4. Always end with a newline (Requirement)
  printf("\n");

  return 0;
}