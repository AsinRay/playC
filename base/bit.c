#include <stdio.h>

int main(){
    printf("%d\n",3&5);
    printf("%d\n",2<<(2<<2));
    // 多个 << 从左向右计算
    printf("3<<2<<1 = %d\n",3<<2<<1);
    printf("3<<(2<<1) = %d\n",3<<(2<<1));
    // 多个 << 从左向右计算
    printf("3<<2<<2= %d\n",3<<2<<2);
    printf("3<<(2<<2)=  %d\n",3<<(2<<2));
    printf("(3<<2)<<2= %d\n",(3<<2)<<2);
    
}