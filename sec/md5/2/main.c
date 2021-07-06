#include <string.h>
#include <stdlib.h>
#include <stdio.h>
//#include <stdbool.h>
//#include <stdarg.h>
//#include <ctype.h>
//#include <limits.h>

#include "md5.h"


int main(){
    char s[] = "1234567";
     const char *payload = s;

    MD5_CTX context = {0};
    MD5Init(&context);
    MD5Update(&context, (unsigned char *) payload, strlen(payload));
    unsigned char dest[16] = {0};
    MD5Final(dest, &context);
    char szMd5[33] = {0};
    szMd5[32]='\0';
    for (int i = 0; i < 16; i++) {
        sprintf(szMd5, "%s%02x", szMd5, dest[i]);
    }
    // print 
    printf("%s\n",szMd5);
}