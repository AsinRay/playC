#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../c.h"

char *concat(char *c1, char *c2)
{
    char *fin = (char *)malloc(strlen(c1) + strlen(c2));
    strcpy(fin, c1);
    strcat(fin, c2);
    return fin;
}

// 全局变量方式实现
char *__sign__;
char *concat1(char *s1, char *s2)
{
    int len = strlen(s1) + strlen(s2) + 1;
    char rtn[len];
    memset(rtn, 0, sizeof(rtn)); //赋数组初值全为0；（使用头文件string.h）
    strcpy(rtn, s1);
    strcat(rtn, s2);
    __sign__ = rtn;
    return __sign__;
}


char * sign_11[1024] = {'\0'};
char * concat11(char *s1, char *s2)
{
    int len = strlen(s1) + strlen(s2) + 1;
    memset(sign_11, 0, sizeof(sign_11)/sizeof(sign_11[0])); //赋数组初值全为0；（使用头文件string.h）

    for (int i = 0; i < len; i++) {
        sign_11[i] = ((s1[i] ^ s2[i]) % 26 + 97);
    }

    sign_11[len] = '\0';
    return sign_11;
}

char *concat2(char *c1, char *c2)
{
    char *fin = (char *)malloc(strlen(c1) + strlen(c2));
    sprintf(fin, "%s%s", c1, c2);
    return fin;
}

char *strnconcat()
{
    char dest[100];
    dest[0] = '\0';
    strncat(dest, "Hello World!", 90);
    printf("Final destination string: %s\n", dest);
}


/**
 * @brief how to concat two string.
 * 
 * @return int 
 */
int main()
{
    char *firstName = "Admin我是中国人";
    char *lastName = "6677i这个是什么";
    char *name = concat(firstName, lastName);
    printf("%s\n", name);
    free(name);

    concat1(firstName, lastName);
    printf("%s\n", __sign__);

   

    strnconcat(firstName, lastName);
    char *nm = concat2(firstName, lastName);
    printf("%s\n", nm);

    printf("%s\n","NNNNNNNNNNNNN");
    printf("%s\n", concat11(firstName,lastName));

    return 0;
}
