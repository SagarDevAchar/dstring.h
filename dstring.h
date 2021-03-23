#include <stdlib.h>

typedef struct dynamicString {
    char *string;
    int length;

    char firstChar;
    char lastChar;
} dstring;

dstring new_dstring(char *str);

int dstrlen(dstring ds);

void dstrrev(dstring *dstr);

int dstrcat(dstring *dest, dstring *source);

int dstrcatr(dstring *dest, char *source);

void dstrcpy(dstring *dest, dstring *source);

void dstrcpyr(dstring *dest, char *source);

int dstrcmp(dstring *dstr1, dstring *dstr2);

int dstrcmpr(dstring *dstr, char *str);

void dstrlower(dstring *dstr);

void dstrupper(dstring *dstr);

dstring dsubstr(dstring *dstr, int start, int length);

char *dsubstrr(dstring *dstr, int start, int length);

int *dstrloc(dstring *dstr, char *c);

void dstrrep(dstring *dstr, char *old, char *new);

void dstrdel(dstring *dstr, char del); // TBC

// INCOMPLETE - Buggy
dstring *dstrsplit(dstring *dstr, char delim);
