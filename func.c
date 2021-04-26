#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int max(int x,int y){return (x>y?x:y);}

char* concat(char *s1,char *s2){
    //printf("s1 is %s",s1);
    //printf("s2 is %s",s2);
    return s1;
}

char* d(char *s1,char *s2){
    //printf("s1 is %s",s1);
    //printf("s2 is %s",s2);
    return s1;
}

char* f(char *s1,char *s2){
    //printf("s1 is %s",s1);
    //printf("s2 is %s",s2);
    return s2;
}



int main(){

    srand((unsigned)time(NULL));;
    int lon = rand();

    int (*pre)(int,int);
    pre = max;
    int a=5;
    int b=6;
    int c = (*pre)(a,b);
    printf("%d为大的数字",c);


    char* c1 ="asdfqwer";
    char* c2 ="qwerasdf5555";
    char* (*p)(char*,char*);

    char prefix;
    switch (lon%2)
    {
    case 0:
        p=d;
        prefix = 'd';
        break;
    case 1:
        p=f;
        prefix = 'c'; 
        break;   
    
    default:
        p = concat;
        break;
    }

    // 动态变化的
    //p=concat;
    lon ++;
    char* c3 = (*p)(c1,c2);
    for(int i=0;i<strlen(c3);i++){
        printf("%c",c3[i]);
    }
    printf("\n");

}

