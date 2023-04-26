#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

long long int onebyte(long long int *p)
{
    long long int a,tem,num=0,flag;
    a=*p;
    tem=1;
    for(int i=0;i<64;i++)
    {
        flag=a&tem;
        if(flag==0);
        else
        {
            num++;
        }
        tem=tem<<1;
    }
    return num;
}
int cmpfunc (const void * a, const void * b)
{
    int flag=0;
    long long int *A,*B,a1,b1;
    A=(long long int*)a;
    B=(long long int*)b;
    a1=onebyte(A);
    b1=onebyte(B);
    if(a1>b1)
        flag=-1;
    else if(a1<b1)
        flag=1;
    else
    {
        if(*A<*B)
            flag=-1;
        else
            flag=1;
    }
    return flag;
}
void myPrint(long long int *c,int len)        //c是排序好了的数组
{
    static int tim=0;
    printf("case #");
    printf("%d",tim);
    printf(":\n");
    for(int i=0;i<len;i++)
    {
        if(i!=len-1)    printf("%lld ",c[i]);
        else    printf("%lld\n",c[i]);
    }
    tim++;
}
int main()
{
    int T,i,j;
    int *a;
    long long int *b;
    scanf("%d",&T);
    a=(int*)malloc(T*sizeof(int));
    for(i=0;i<T;i++)
    {
        scanf("%d",&a[i]);
        b=(long long int*)malloc(a[i]*sizeof(long long int));
        for(j=0;j<a[i];j++)
        {
            scanf("%lld",&b[j]);
        }
        qsort(b,a[i],sizeof(long long int),cmpfunc);
        myPrint(b,a[i]);
    }
	return 0;
}
