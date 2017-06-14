#ifndef RC4_H
#define RC4_H
unsigned char* ksa(unsigned char* key);
unsigned char* generate_keystream(int stream_size, unsigned char* S);
#endif
