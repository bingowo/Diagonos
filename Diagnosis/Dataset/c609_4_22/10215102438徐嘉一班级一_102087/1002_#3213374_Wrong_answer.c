#include <stdio.h>
#include <stdlib.h>
#define N 32
int dec(int n)
{
    int s[N],sum,k=0;
    do{
        s[k++]=n%2;//k位数组
        n=n/2;
    }while(n);
    sum=1;
    for(int i=1;i<k;i++)
    {
        if(s[i]!=s[i-1])
            sum++;
        else
            continue;
    }
    return sum;
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int n;
        scanf("%d",&n);
        printf("case #%d:\n",i);
        printf("%d\n",dec(n));
    }
    return 0;
}
