#define __STDC_WANT_LIB_EXT1__ 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * 
    void *memset(void *s, int ch, size_t n);

    函数解释：将s中当前位置后面的n个字节用 ch 替换并返回 s 。

    参数：s，指针，要赋值的内存的起始地址。

    ch，用于设置给内存块的值。

    n，指定设置为ch值的字节数

    作用：在一段内存块中填充某个给定的值，它是对较大的结构体或数组进行清零操作的一种最快方法。

    由函数解释可以知道，memset函数是对地址为s开始的n个字节的内存块进行赋值，而且是将这个n个字节的每个字节赋值为整数ch。
    这一点要注意，使用memset函数对内存块赋值是以字节为单位来赋值。

 */

//

// 示例1    清零操作 - 使用memset函数对char类型的数组进行清零操作
void setZeroChar(){

    int i;
	char ArrCh[10] = {0};
    int sz = sizeof(ArrCh);
	memset(ArrCh, 0, sz);	
	printf("char type, assign zero value:\n");
	for(i=0; i<sz; i++)
	{
		printf("0x%x, ", ArrCh[i]);
	}
	printf("\n");
}

// 示例2 设置为非零值 - 使用memset函数对char类型的数组赋为非0值操作
void setNoneZeroChar(){
    int i;
	char ArrCh[10] = {0};
	int sz = sizeof(ArrCh);
	memset(ArrCh, 0x4, sz);		//赋值为0x4 
	
	printf("char type, assign non zero value:\n");
	for(i=0; i<sz; i++)
	{
		printf("0x%x, ", ArrCh[i]);
	}
	printf("\n");
}

// 示例3 int类型数组清零 - 使用memset函数对int类型的数组进行清零操作
void setZeroInt(){
    int i;
	int ArrInt[10] = {0};
	int sz = sizeof(ArrInt);
	memset(ArrInt, 0, sz);
	
	//打印数组大小、元素类型大小、数组元素个数 
	printf("sizeof(ArrInt):%d, sizeof(int):%d, element counts of ArrInt:%d\n", 
			sz, sizeof(int), sz/sizeof(int));		
	printf("int type, assign zero value:\n");
	for(i=0; i<sz/sizeof(int); i++)
	{
		printf("0x%x, ", ArrInt[i]);
	}
	printf("\n");
}

// 示例4 int类型数组赋为非0值操作 - 使用memset函数对int类型的数组赋为非0值操作

// 返回结果：
// int type, assign non zero value:
// 0x4040404, 0x4040404, 0x4040404, 0x4040404, 0x4040404, 0x4040404, 0x4040404, 0x4040404, 0x4040404, 0x4040404,

// 对int类型数组的每个元素赋值为0x4，但从运行效果来看，int类型数据的每个元素的值却变为0x4040404，与我们预期的不一致。
// 这很显然是错误的，为什么会出错呢？ 因为使用memset函数对内存块赋值是以字节为单位来赋值

// 使用memset函数对内存块赋值是以字节为单位来赋值。所以使用memset函数对char类型数组进行赋值（0值或者非0值）都正确，
// 因为char类型数组的元素大小都是1个字节，刚好与memset函数以字节为单位进行赋值一致。而int类型数组，
// 我们示例代码int类型大小是4个字节，即int类型数组每个元素都是以4个字节为一个单位，“对int类型数组赋0值正确”，
// 这个很好理解，因为将整个内存的每个字节都赋为0值，那么无论这个内存是存放什么数据类型的内存，
// 即无论是以多少个字节作为一个单位，该单位打印出来的值都是0。

// 为何int类型数组赋为非0值，每个元素打印出来的值与我们预期不同？因为ArrInt数组的元素是int类型，大小是4个字节，
// 那么每个元素都是4个字节，又由于memse函数是对内存块的每个字节赋值，所以是示例代码中，ArrInt数组的所占内存每个字节都是值0x4，
// 所以ArrInt数组的一个int元素是4个字节且每个字节值为0x4，表示出来就是0x4040404（由于每个字节的值相同，表示该值可以不考虑大小端字节序），
// 与打印出来的是一致的。
void setNoneZeroInt(){
    int i;
	int ArrInt[10] = {0};
	int sz = sizeof(ArrInt);
	memset(ArrInt, 0x4, sz);		//赋值为0x4 
	
	//打印数组大小、元素类型大小、数组元素个数 
	printf("sizeof(ArrInt):%d, sizeof(int):%d, element counts of ArrInt:%d\n", 
			sz, sizeof(int), sz/sizeof(int));		
	printf("int type, assign non zero value:\n");
	for(i=0; i<sz/sizeof(int); i++)
	{
		printf("0x%x, ", ArrInt[i]);
	}
	printf("\n");
}

// 示例5 验证 memset在int数组中的非零设置 
void vSetNoneZeroInt(){
    printf("%s\n","// 示例5 验证 memset在int数组中的非零设置 ");
    int i;
	int ArrInt[10] = {0};
	int sz = sizeof(ArrInt);
	memset(ArrInt, 0x4, sz);		//赋值为0x4 
	
	//打印数组大小、元素类型大小、数组元素个数 
	printf("sizeof(ArrInt):%d, sizeof(int):%d, element counts of ArrInt:%d\n", 
			sz, sizeof(int), sz/sizeof(int));		
	printf("int type, assign non zero value, print as char unit:\n");
    char* pCh = (char*) ArrInt;
    printf("%d\n",sizeof(pCh));
    printf("%d\n",sz);
    printf("sizeof(int) %d\n",sizeof(int));
    printf("sizeof(char) %d\n",sizeof(char));

	for(i=0; i<sz/sizeof(int); i++)
	{
		printf("0x%x, ", ArrInt[i]);
	}
	printf("\n");
}


// 示例6 int数组中的非零设置的正确方法 
void setNoneZeroInt_s(){
    printf("%s\n","// 示例6 int数组中的非零设置的正确方法 ");

    int i;
	int ArrInt[10] = {0};
    int sz = sizeof(ArrInt);
	//赋值为0x4 
    for(i=0;i<sz/sizeof(int);i++){
        ArrInt[i]=0x4;
    }

	//打印数组大小、元素类型大小、数组元素个数 
	printf("sizeof(ArrInt):%d, sizeof(int):%d, element counts of ArrInt:%d\n", 
			sz, sizeof(int), sz/sizeof(int));	
    	
	for(i=0; i<sz/sizeof(int); i++)
	{
		printf("0x%x, ", ArrInt[i]);
	}
	printf("\n");
}


void msetArr(){
     // 静态数组arr
    int arr[10];

    printf("%d\n",sizeof(arr));
    // 将数组所有元素初始化为0
    memset(arr,0,sizeof(arr));
   	// 遍历输出数组元素
    for(int i=0;i<10;++i){
        printf("%s\n",arr[i]);
    }
}

// 示例2
void msetArr2(){

    int arr[10] = {0};
    // 将数组所有元素初始化为0
    memset(arr,0,sizeof(arr));
   	// 遍历输出数组元素
    for(int i=0;i<10;++i){
        printf("%s\n",arr[i]);
    }
}

 
int main(void)
{

    char str[] = "abcdefgh";
    puts(str);
    memset(str,'a',5);
    puts(str);


    // 当出现了长度大于原长度时，出现 Segmentation fault
    //memset(str,'X',18);
    //puts(str);

    printf("%s\n","FFFFFFFFFFFFFFFF");

    char s[128]={0};
    puts(s);
    printf("%d\n",sizeof(s));
    memset(s,'0',sizeof(s));


    // 我们可以在上面两份代码中输出sizeof(arr)，可以发现结果是不一样的
    // 因为在第一份代码中arr代表一个数组，第二份代码中arr代表一个指针。

    msetArr();
    msetArr2();


    // func

    setZeroChar();
    setNoneZeroChar();

    setZeroInt();
    setNoneZeroInt();
    vSetNoneZeroInt();
    setNoneZeroInt_s();


 
#ifdef __STDC_LIB_EXT1__
    set_constraint_handler_s(ignore_handler_s);
    int r = memset_s(str, sizeof str, 'b', 5);
    printf("str = \"%s\", r = %d\n", str, r);
    r = memset_s(str, 5, 'c', 10);   // count is greater than destsz  
    printf("str = \"%s\", r = %d\n", str, r);
#endif
}