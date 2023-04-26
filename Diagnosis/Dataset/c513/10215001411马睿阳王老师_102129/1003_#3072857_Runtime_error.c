#include<stdio.h>
#include<string.h>

int cmp(const void*a1,const void*a2)
{
    int t=0,e=0,num1,num2;
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
    while(b!=0&e<64)
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

int main()
{
    int T,N,i;
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        scanf("%d",&N);
        long long int s[10000];
        long long int j;
        for(j=0;j<N;j++)
            scanf("%lld",s[j]);
        qsort(s,j,sizeof(s[0]),cmp);
        printf("case #%d:\n",i);
        for(j=0;j<N;j++)
            printf("%lld\n",s[j]);
    }
    return 0;
}
