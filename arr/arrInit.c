#include <stdio.h>

void arr()
{
    int i, a[10];

    for (i = 0; i < 10; i++)
    {
        a[i] = i;
        printf("%d", i);
    }
    printf("\n");

    for (i = 9; i >= 0; i--)
    {
        printf("%d", a[i]);
    }
    printf("\n=================\n");
}

int main()
{
    // 初始化
    int a[10] = {0,1,2,3,4,5,6,7,8,9};
    
    // 部分初始化,后面没有指定的初始化为0
    int b[10] = {0,1,2,3,4};

    // 依照上一规则，初始化全0数组为：
    int c[10] = {0};
    // 自动计算数组的长度，不需要指定
    int d[] = {1,2,3,4,5};

    arr();
}
