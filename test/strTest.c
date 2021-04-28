#include <stdio.h>
#include <string.h>
#include <limits.h>

int main(){
    char s1[5] = {'h','e','l','l','o'};
    char s2[] = "hello";

    char s[5];
    s[0]='h';
    s[1]='e';
    s[2]='l';
    s[3]='l';
    s[5]='o';


    printf("%d, %d\n",strlen(s1), sizeof(s1));
    printf("%d, %d\n",strlen(s2), sizeof(s2));
    printf("%d, %d\n",strlen(s) , sizeof(s));
    printf("============\n");
  
}