#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

    char *dest = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char szMd5[33] = {0};

    for (short i = 0; i < 16; i++)
    {
        if(i==0){
             sprintf(szMd5, "%s%02x", szMd5, 'a');
        }else{
            sprintf(szMd5, "%s%02x", szMd5, dest[i-1]);
        }
    }

    for (short i = 0; i < 32; i++)
    {
        printf("%c\n",szMd5[i]);
        /* code */
    }
    
}