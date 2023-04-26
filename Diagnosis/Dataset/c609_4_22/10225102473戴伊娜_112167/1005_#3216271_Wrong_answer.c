#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int T;
    scanf("%d",&T);
    int  a[50];
    char c;
    long long int sum;
    for(int q=0;q<T;q++)
    {
    for(int i=0;c=getchar()!=EOF;i++)
    {
        scanf("%c",&c);
        if(c=='1')
            a[i]=1;
        if(c=='-')
            a[i]=-1;
        if(c=='0')
            a[i]=0;
        sum=sum*3+a[i];
    }
    printf("case #%d:\n",q);
    printf("%lld",sum);
    }
}
