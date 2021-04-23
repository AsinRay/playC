#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "c.h"



char arr[3] = {36,'b',3};


char* xor(char *s1, char *s2){
    int len = min(strlen(s1),strlen(s2));
    // need free
    char* result = (char*) malloc(len*sizeof(char));
    //in real code you would check for errors in malloc here
    if (result == NULL) exit (1);

    for(int i = 0;i<len;i++){
       int x = (s1[i]^s2[i])%26;
       result[i] =  (char)(x + 97);
    }
    return result;
}

int main(){

   printf("%s\n","asdfas");
   char* c1 ="0123456789abcdef";
   char* c2 ="23456789abcdefxx0ook";
   char* rtn = xor(c1,c2);

   char x = (char)97;
   printf("%c",x);

   free(rtn);
   rtn = NULL;
}