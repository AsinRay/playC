#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "md5.h"

int main(int argc, char *argv[])
{

    int i;
    //char payload[] ="admin";//21232f297a57a5a743894a0e4a801fc3
    char payload[] ="1234567";//21232f297a57a5a743894a0e4a801fc3
    unsigned char dest[16];
    int len = strlen((char *) payload);
    MD5_CTX md5;
    MD5Init(&md5);
    MD5Update(&md5,payload,len);
    MD5Final(&md5,dest);
    printf("加密前:%s\n加密后:",payload);
    for(i=0;i<16;i++)
    {
        printf("%02x",dest[i]);
    }

    getchar();

    return 0;
}