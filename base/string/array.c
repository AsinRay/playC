#include <stdio.h>
#include <string.h>
#include "../c.h"

unsigned char *cxorX(char *dest, char *s1, char *s2) {
    char* r = dest;
    int len = min(strlen(s1), strlen(s2));
    char  rtn[len+1];
    memset(rtn,0,sizeof(rtn));//赋数组初值全为0；（使用头文件string.h）
    for (int i = 0; i < len; i++) {
        rtn[i] = (s1[i] ^ s2[i]) % 26 + 97;
    }
    return dest;
}



unsigned char *cxor(char *dest, char *s1, char *s2) {
    int len = min(strlen(s1), strlen(s2));
    memset(dest,0,sizeof(dest));//赋数组初值全为0；（使用头文件string.h）
    for (int i = 0; i < len; i++) {
        dest[i] = (s1[i] ^ s2[i]) % 26 + 97;
    }
    return dest;
}

int main(){

    // 传入指针

    char * dest[1024];
    printf("%d\n",sizeof(dest));
    printf("%d\n",sizeof(dest[0]));
    printf("%d\n",sizeof(dest)/sizeof(dest[0]));









    return 0;
}