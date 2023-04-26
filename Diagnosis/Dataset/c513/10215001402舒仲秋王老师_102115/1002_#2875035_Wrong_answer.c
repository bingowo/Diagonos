#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
void turn(char s[])
{
    int a[128],i,digit=0,N=1; ;char *p=s;
    for(i=0;i<128;i++) a[i]=-1;
    a[*p]=1;
    while (*++p)
    {
        if (a[*p]==-1)   {a[*p]=digit; digit=digit?digit+1:2; N++;}
        if (N<2) N=2;
    }
    long long ans=0;
    p=s; while (*p) ans=ans*N+a[*p++];
    printf("%lld\n",ans);
}

int main()
{
    int N,i;
    char s[100][100];
    scanf("%d",&N);
    for(i=0;i<N;i++)
    {
        scanf("%s",s[i]);
    }
    for(i=0;i<N;i++)
    {
        printf("case #%d:\n",i);
        turn(s[i]);
    }

    return 0;
}
