#include "libtruerand.h"
#include "rc4.h"
#include "key_handler.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
	int stream_size = atoi(argv[1]);
	printf("size: %d\n", stream_size);
	FILE* keyfile = fopen("keyfile", "rb");
	FILE* output = fopen("keystream.data", "wb");
	unsigned char* key;

	if(keyfile) {
		printf("keyfile found.\n");
		key = read_key(keyfile);
	}
	else {
		printf("keyfile not found. Generating key....\n");
		key = (unsigned char*)generate_key(16);
		keyfile = fopen("keyfile", "wb");
		printf("tamanho da key: %d\n", (int)strlen((char*)key));
		fwrite(key, sizeof(char), strlen((char*)key), keyfile);
		fwrite("\n", sizeof(char), 1, keyfile);
	}
	
	printf("key: %s\n", key);
	unsigned char* keystream = generate_keystream(stream_size, key);
	fwrite(keystream, sizeof(char), stream_size, output);

  return 0;
}
