#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "c.h"

char arr[3] = {36, 'b', 3};

/**
 * 字母表
 * @param s1
 * @param s2
 * @return
 */

char* xor (char *s1, char *s2) {
   int len = min(strlen(s1), strlen(s2));
   // need free
   char* result = (char *)malloc(len);
   //in real code you would check for errors in malloc here
   if (result == NULL)
      exit(1);

   for (int i = 0; i < len; i++)
   {
      result[i] = (s1[i] ^ s2[i]) % 26 + 97;
   }
   return result;
}

    /**
 * ASCII 表
 * @param s1
 * @param s2
 * @return
 */
char* axor(char *s1, char *s2)
{
   int len = min(strlen(s1), strlen(s2));
   // need free
   char *result = (char *)malloc(len);
   //in real code you would check for errors in malloc here
   if (result == NULL)
      exit(1);

   for (int i = 0; i < len; i++)
   {
      result[i] = (s1[i] ^ s2[i]) % 127 + 1;
   }
   return result;
}

/**
 * 链式xor
 * @param s1
 * @param s2
 * @return
 */
char* chainXor(char *s1, char *s2)
{
   int len = min(strlen(s1), strlen(s2));
  
   // need free
   char *result = (char *)malloc(len);
   //in real code you would check for errors in malloc here
   if (result == NULL)
      exit(1);

   char *src = len == strlen(s1) ? s1 : s2;
   result[0] = (len ^ src[0])%26 + 97;
   for (int i = 1; i < len; i++)
   {
      result[i] = (result[i-1] ^ src[i]) % 26 + 97;
   }
   return result;
}

int main()
{
   char *c1 = "getUserAccountInfoBySecretNew";
   char *c2 = "6e4069678612b2f5b54e28be184967ab";

/*    printf("%s\n", "========== chainXor ========");
   char* rtn = chainXor(c1, c2);
   free(rtn);

   for (int i = 0; i < strlen(rtn); i++){
      printf("%c", rtn[i]);
   }
   printf("\n");
   free(rtn); */


   printf("%s\n", "========== xor ========");
   char* rtn = xor(c1, c2);
   for (int i = 0; i < strlen(rtn); i++){
      printf("%c", rtn[i]);
   }
   printf("\n");
   free(rtn);


/*    printf("%s\n", "========== axor ========");
   rtn = axor(c1, c2);
   for (int i = 0; i < strlen(rtn); i++){
      printf("%d\n", rtn[i]);
   }
   printf("8888>>>\n");
   free(rtn); */

   rtn = NULL;
}