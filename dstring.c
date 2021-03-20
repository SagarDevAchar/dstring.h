#include <stdio.h>
#include <stdlib.h>

typedef struct dynamicString {
    char* string;
    int length;

    char firstChar;
    char lastChar;
} dstring;

dstring new_dstring(char* str) {
    dstring ds;
    ds.string = (char*)malloc(sizeof(char));
    ds.length = 0;

    ds.firstChar =* str;

    for (;* str ; str++) {
       * (ds.string + ds.length) =* str;
        ds.length++;
    }

   * (ds.string + ds.length) = '\0';
    ds.lastChar =* (str - 1);

    return ds;
};

static int rstrlen(char* str) {
    int l = 0;
    for (;* str ; str++)
        l++;
    return l;
}

int dstrlen(dstring ds) {
    return ds.length;
}

int dstrcat(dstring* dest, dstring* source) {
    char* destPtr = dest->string;
    destPtr += dest->length;

    for (char* sourcePtr = source->string ;* sourcePtr ; sourcePtr++) {
       * destPtr =* sourcePtr;
        destPtr += 1;
    }

   * destPtr = '\0';

    dest->length += source->length;

    return dest->length;
}

int dstrcatr(dstring* dest, char* source) {
    char* destPtr = dest->string;
    destPtr += dest->length;

    for (;* source ; source++) {
       * destPtr =* source;
        destPtr++;;
        dest->length++;
    }

   * destPtr = '\0';

    return dest->length;
}

void dstrcpy(dstring* dest, dstring* source) {
    char* destPtr = dest->string;

    for (char* sourcePtr = source->string ;* sourcePtr ; sourcePtr++) {
       * destPtr =* sourcePtr;
        destPtr += 1;
    }

   * destPtr = '\0';

    dest->length = source->length;
}

void dstrcpyr(dstring* dest, char* source) {
    char* destPtr = dest->string;
    dest->length = 0;

    for (;* source ; source++) {
       * destPtr =* source;
        destPtr++;
        dest->length++;
    }

   * destPtr = '\0';
}

int dstrcmp(dstring* dstr1, dstring* dstr2) {
    if (dstr1->length == dstr2->length) {
        char* s1 = dstr1->string;

        for (char* s2 = dstr2->string ;* s2 ; s2++) {
            if (*s1 !=* s2)
                return 0;
            s1++;
        }
        return 1;
    } else {
        return 0;
    }
}

int dstrcmpr(dstring* dstr, char* str) {
    if (dstr->length == rstrlen(str)) {
        for (char* s = dstr->string ;* s ; s++) {
            if (*s !=* str)
                return 0;
            str++;
        }
        return 1;
    } else {
        return 0;
    }
}

void dstrlower(dstring* dstr) {
    for (char* str = dstr->string ;* str ; str++) {
        if (*str >= 65 &&* str <= 90)
           * str += 32;
    }
}

void dstrupper(dstring* dstr) {
    for (char* str = dstr->string ;* str ; str++) {
        if (*str >= 97 &&* str <= 122)
           * str -= 32;
    }
}

dstring dsubstr(dstring* dstr, int start, int length) {
    char* ss = (char*)malloc(sizeof(char));
    char* s = dstr->string;

    int l = 0;

    for (s += start; l < length; s++) {
       * (ss + l) =* s;
        l++;
    }
   * (ss + l) = '\0';

    return new_dstring(ss);
}

char* dsubstrr(dstring* dstr, int start, int length) {
    char* ss = (char*)malloc(sizeof(char));
    char* s = dstr->string;

    int l = 0;

    for (s += start; l < length; s++) {
       * (ss + l) =* s;
        l++;
    }
   * (ss + l) = '\0';

    return ss;
}

void dstrrev(dstring* dstr) {
    char* str = dstr->string;
    int L = dstr->length;

    for (int i = 0 ; i < (int)(L / 2) ; i++) {
        char temp =* (str + i);
       * (str + i) =* (str + L - i - 1);
       * (str + L - i - 1) = temp;
    }
}

// INCOMPLETE - Buggy
dstring* dstrsplit(dstring* dstr, char delim) {
    dstring* splitres2 = (dstring*)malloc(sizeof(dstring));
    dstring splitres = new_dstring("");
    for (char* str = dstr->string ; *str ; str++) {
        if (*str == delim) {
            dstrcatr(&splitres, "\0");
            printf("DEBUG : Split : %s\n", splitres.string);
            //splitres++;
            splitres = new_dstring("");
        } else {
            dstrcatr(&splitres, str);
            printf("DEBUG : Split Append : %s\n", splitres.string);
        }
    }
    dstrcatr(&splitres, "\0");

    return splitres2;
}

// TO BE WRITTEN
int dstrcountc(dstring* dstr, char c) {

}

int dstrcounts(dstring* dstr, char* c) {

}