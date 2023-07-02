#ifndef _PLAYFAIR_H
#define _PLAYFAIR_H

#define ALPHA "ABCDEFGHIJKLMNOPQRSTUVXYZ"

char* playfair_encrypt(const char* key, const char* text);

char* playfair_decrypt(const char* key, const char* text);

#endif
