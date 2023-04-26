#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T,question_num;
    scanf("%d",&T);
    for(question_num=0;question_num<T;question_num++)
    {
        int n;
        scanf("%d",&n);
        long long int a[51]={0};
        a[1]=1;
        a[2]=2;
        a[3]=4;
        a[4]=8;
        for(i=5;i<=n;i++)
           a[i]=a[i-1]+a[i-2]+a[i-3]+a[i-4];
        printf("case #%d:\n%lld\n",question_num,a[n]);
    }
}