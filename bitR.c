#include <stdio.h>
int main(){

    // 有符号数右移前面补1
    unsigned char a = -2;
    a = a >> 1;
    printf("%d\n",a);

    // 无符号数右移，前面不补1
    signed char b = -2;
    b = b >> 1;
    printf("%d\n",b);


    // 设置一个低4位为1，其它位为0的数,可移植性 
    //         0取反        左移4位      再取反
    // 00000000 -> 11111111 -> 11110000 -> 00001111
    int i = ~((~0)<<4);
    int j = ~(~0<<4);
    printf("%d,%d\n",i,j);


    printf("%d\n",sizeof(char)*8);

    int x = 'A';
    printf("%c\n",x^32);

    int y='a';
    printf("%c\n",y^1<<5);
}