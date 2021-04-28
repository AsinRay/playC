    //t.c
    #include<stdio.h>
    #include<string.h>

    int foo(int n){
    	int x[n];
    	printf("%lu\n",sizeof(x));
    	return n;
    }

     int f(int n){
        int m = 5;
    	char x[m];
        printf("param is:%d:\n",n);
        printf("len is: %d\n",strlen(x));
        int i ;
        for(i = 0;i<n;i++){
            x[i] = i + 97;
            printf("%d: %d\n",x[i],i);
        }
    	printf("%s\n",x);
    	return n;
    }
     
    int main()
    {

        f(9);
    	foo(10);
    	foo(20);
    	return 0;
    }