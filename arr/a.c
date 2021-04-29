#include <stdio.h>

int main(){
    int i, a[5] = {3,4,5},b[5];
    printf("\n array a is :");
    for(int i=0;i<5;i++) printf("%6d",a[i]);

    printf("\n array b is:");
    for(int i=0;i<5;i++) printf("\t%d",b[i]);

    unsigned int u =-100;
    printf("\n%d\n",u+5);
}
