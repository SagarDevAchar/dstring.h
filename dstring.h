#include <stdlib.h>

typedef struct dynamicString {
    char* string;
    int length;

    char firstChar;
    char lastChar;
} dstring;

dstring new_dstring(char* str);

int dstrlen(dstring ds);

int dstrcat(dstring* dest, dstring* source);

int dstrcatr(dstring* dest, char* source);

void dstrcpy(dstring* dest, dstring* source);

void dstrcpyr(dstring* dest, char* source);

int dstrcmp(dstring* dstr1, dstring* dstr2);

int dstrcmpr(dstring* dstr, char* str);

void dstrlower(dstring* dstr);

void dstrupper(dstring* dstr);

dstring dsubstr(dstring* dstr, int start, int length);

char* dsubstrr(dstring* dstr, int start, int length);

void dstrrev(dstring* dstr);

// INCOMPLETE - Buggy
dstring* dstrsplit(dstring* dstr, char delim);

int dstrcountc(dstring* dstr, char c);

int dstrcounts(dstring* dstr, char* c);