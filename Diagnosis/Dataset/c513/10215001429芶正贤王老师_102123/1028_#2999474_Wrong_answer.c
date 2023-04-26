#include<stdio.h>
#include<stdlib.h>

int cmpfuncA(const void * a,const void * b)
{
    return(*(int*)a - *(int*)b);
}
int cmpfuncD(const void * a,const void * b)
{
    return(*(int*)b - *(int*)a);
}

int main()
{
    char ch;
    ch = getchar();
    long long int a[100];
    int i,j;
    for(i = 0;i<101;i++)
    {
        scanf("%lld",&a[i]);     //空格符or换行符分隔
        printf("%lld ",a[i]);
    }
        
    
    
    return 0;
}



