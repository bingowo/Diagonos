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
    for(i = 0;scanf("%lld",&a[i]) != EOF;i++);
        
    
    if(ch == 'A')
    {
        qsort(a,i+1,sizeof(long long int),cmpfuncA);
    }
    
    if(ch == 'D')
    {
        qsort(a,i+1,sizeof(long long int),cmpfuncD);
    }
    
    if(i>0)
    {
        for(j=0;j<i;j++)
            printf("%lld",a[j]);
        printf("%lld",a[i]);
    }
    else
        printf("%lld",a[i]);

    return 0;
}



