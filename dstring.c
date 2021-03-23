#include <stdio.h>
#include <stdlib.h>

static int rstrlen(char *str) {
    int l = 0;
    for (; *str ; str++)
        l++;
    return l;
}


typedef struct dynamicString {
    char *string;
    int length;

    char firstChar;
    char lastChar;
} dstring;

dstring new_dstring(char *str) {
    dstring ds;
    ds.string = (char*)malloc(sizeof(char) * rstrlen(str) + 1);
    ds.length = 0;

    ds.firstChar = *str;

    for (; *str ; str++) {
       *(ds.string + ds.length) = *str;
        ds.length++;
    }

   *(ds.string + ds.length) = '\0';
    ds.lastChar = *(str - 1);

    return ds;
};

int dstrlen(dstring ds) {
    return ds.length;
}

void dstrrev(dstring *dstr) {
    char *str = dstr->string;
    int L = dstr->length;

    for (int i = 0 ; i < (int)(L / 2) ; i++) {
        char temp = *(str + i);
        *(str + i) = *(str + L - i - 1);
        *(str + L - i - 1) = temp;
    }
}

int dstrcat(dstring *dest, dstring *source) {
    dest->string = (char*)realloc(dest->string, sizeof(char) * (dest->length + source->length + 1));

    char *destPtr = dest->string;
    destPtr += dest->length;

    for (char *sourcePtr = source->string ; *sourcePtr ; sourcePtr++) {
        *destPtr = *sourcePtr;
        destPtr += 1;
    }

    *destPtr = '\0';

    dest->length += source->length;

    return dest->length;
}

int dstrcatr(dstring *dest, char *source) {
    char *destPtr = dest->string;
    destPtr += dest->length;

    for (; *source ; source++) {
        *destPtr = *source;
        destPtr++;
        dest->length++;
    }

    *destPtr = '\0';

    return dest->length;
}

void dstrcpy(dstring *dest, dstring *source) {
    char *destPtr = dest->string;

    for (char *sourcePtr = source->string ; *sourcePtr ; sourcePtr++) {
        *destPtr = *sourcePtr;
        destPtr += 1;
    }

    *destPtr = '\0';

    dest->length = source->length;
}

void dstrcpyr(dstring *dest, char *source) {
    char *destPtr = dest->string;
    dest->length = 0;

    for (; *source ; source++) {
        *destPtr = *source;
        destPtr++;
        dest->length++;
    }

    *destPtr = '\0';
}

int dstrcmp(dstring *dstr1, dstring *dstr2) {
    if (dstr1->length == dstr2->length) {
        char *s1 = dstr1->string;

        for (char *s2 = dstr2->string ; *s2 ; s2++) {
            if (*s1 != *s2)
                return 0;
            s1++;
        }
        return 1;
    } else {
        return 0;
    }
}

int dstrcmpr(dstring *dstr, char *str) {
    if (dstr->length == rstrlen(str)) {
        for (char *s = dstr->string ; *s ; s++) {
            if (*s != *str)
                return 0;
            str++;
        }
        return 1;
    } else {
        return 0;
    }
}

void dstrlower(dstring *dstr) {
    for (char *str = dstr->string ; *str ; str++) {
        if (*str >= 65 && *str <= 90)
            *str += 32;
    }
}

void dstrupper(dstring *dstr) {
    for (char *str = dstr->string ; *str ; str++) {
        if (*str >= 97 && *str <= 122)
            *str -= 32;
    }
}

dstring dsubstr(dstring *dstr, int start, int length) {
    char *ss = (char*)malloc(sizeof(char));
    char *s = dstr->string;

    int l = 0;

    for (s += start; l < length; s++) {
        *(ss + l) = *s;
        l++;
    }
    *(ss + l) = '\0';

    return new_dstring(ss);
}

char *dsubstrr(dstring *dstr, int start, int length) {
    char *ss = (char*)malloc(sizeof(char));
    char *s = dstr->string;

    int l = 0;

    for (s += start; l < length; s++) {
        *(ss + l) = *s;
        l++;
    }
    *(ss + l) = '\0';

    return ss;
}

int *dstrloc(dstring *dstr, char *c) {
    int *locs = (int*)malloc(sizeof(int)  *1);
    int count = 0;
    int cs = rstrlen(c);

    *(locs + count + 1) = 0;
    for (char *str = dstr->string ; *(str + cs - 1) ; str++) {
        dstring dss = dsubstr(dstr, *(locs + count + 1), cs);
        if (dstrcmpr(&dss, c) == 1) {
            count++;
            *(locs + count + 1) = *(locs + count);
        }

        *(locs + count + 1) += 1;
    }
    *(locs + count + 1) = EOF;
    *locs = count;

    return locs;
}

/*
void dstrrep(dstring *dstr, char old, char new) {
    for (char *str = dstr->string ; *str ; str++) {
        if (*str == old)
           *str = new;
    }
}
*/

void dstrrep(dstring *dstr, char *old, char *new) {
    int *locs = dstrloc(dstr, old);
    int nl = rstrlen(new);
    char *str = dstr->string;
    
    for (int i = 0 ; i < *locs ; i++)
        for (int l = 0 ; l < nl ; l++)
            *(str + *(locs + i) + l) = *(new + l);

    /*
    for (char *str = dstr->string ; *str ; str++) {
        if (*str == old)
           *str = new;
    }*/
}

void dstrdel(dstring *dstr, char del) {

}

// INCOMPLETE - Buggy
dstring *dstrsplit(dstring *dstr, char delim) {
    dstring *splitres;// = (dstring*)malloc(sizeof(dstring));
    int splitcount = 0;

    //*splitres = new_dstring("");
    //char *splitstr = splitres->string;

    int spliti = 0;
    int splitl = 0;
    for (char *str = dstr->string ; *str ; str++) {
        if (*str == delim) {
            //*splitres = (dstring*)realloc(splitres, sizeof(dstring)  *(splitcount + 2))
            //printf("DEBUG : Post Split dsubstr : %s\n", dsubstr(dstr, spliti, splitl).string);
            *(splitres + splitcount) = new_dstring(dsubstrr(dstr, spliti, splitl));

            //*splitstr = '\0';
            printf("DEBUG : Post Split : %s\n", (splitres + splitcount)->string);
            
            splitcount++;
            spliti += (splitl + 1);
            splitl = 0;

            *(splitres + splitcount) = new_dstring("");
        } else {
            splitl++;
            //*splitstr = *str;
            //printf("DEBUG : Split Append : %s\n", splitres->string);
            //splitstr++;
        }
    }
    //*splitstr = '\0';
    //splitres -= splitcount;

    for (int i = 0 ; i < splitcount ; i++) {
        printf("DEBUG : Split Out : %s\n", (splitres + i)->string);
    }

    return splitres;
}
