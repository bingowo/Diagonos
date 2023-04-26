#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int compar(const void *p1,const void *p2);
void myPrint(long long *temp,int N);
int main()
{
    int T,N,i;
    long long *temp;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&N);
        temp=(long long *)malloc(N*sizeof(long long));
        for(i=0;i<N;i++)
            scanf("%lld",&temp[i]);
        qsort(temp,N,sizeof(long long),compar);
        myPrint(temp,N);
    }
    return 0;
}

int compar(const void *p1,const void *p2)
{
    int flag=0;
    long long *a=(long long*)p1,*b=(long long*)p2;
    long long A=llabs(*a),B=llabs(*b);
    while(A>=10)
        A/=10;
    while(B>=10)
        B/=10;
    if(A>B)
        flag=-1;
    else if(A<B)
        flag=1;
    else
    {
        if(*a<*b)
            flag=-1;
        else
            flag=1;
    }
    return flag;
}
void myPrint(long long *temp,int N)
{
    static int tim=0;
    int i;
    printf("case #%d:\n",tim++);
    for(i=0;i<N;i++)
    {
        printf("%lld ",temp[i]);
    }
    printf("\n");
}
