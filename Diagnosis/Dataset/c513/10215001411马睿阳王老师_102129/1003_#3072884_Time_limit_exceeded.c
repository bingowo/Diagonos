#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void sort(long long int*p,int n)
{int cmp(const void*a1,const void*a2)
{
    int t=0,e=0,num1=0,num2=0;
    long long int a=*(long long int*)a1;
    long long int b=*(long long int*)a2;
    long long int b1=a;
    long long int b2=b;
    while(a!=0&&t<64)//(64位补码)
    {
        if(a&1)
        {
            num1++;
            a>>=1;
            t++;
        }
    }
    while(b!=0&&e<64)
    {
        if(b&1)
        {
            num2++;
            b>>=1;
            e++;
        }
    }
    if(num1>num2) return -1;
    else if(num2<num1) return 1;
    else if(b1<b2) return -1;
    else return 1;
}
qsort(p,n,sizeof(long long int),cmp);
}

int main()
{
    int T,i;
    long long int N;
    scanf("%d\n",&T);
    for(i=0;i<T;i++)
    {
        
        scanf("%lld\n",&N);
        long long int s[10000];
        long long int j;
        for(j=0;j<N;j++)
            scanf("%lld",&s[j]);
        sort(s,N);
        printf("case #%d:\n",i);
        for(j=0;j<N;j++)
            printf("%lld ",s[j]);
        printf("\n");
    }
    return 0;
}
