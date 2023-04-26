#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int main()

{
    int b[150];
    char c[150];
    long long  t1=0,t2=0;
    scanf("%s",c);
    int n=3;
    for (int i=2; i<strlen(c); i++)
    {
        int m=0;
        if ('0'<=c[i]&&c[i]<='9') m=c[i]-'0';
        else m=c[i]-'a'+10;

        for (int j=0; j<4; j++)
        {
            b[n-j]=m&1;
            m=m>>1;

        }
        n=n+4;
    }
    for (int i=0; i<n-3; i++)
    {
        long long w=t1;
        t1=-t1-t2;
        t2=w-t2;
        t1=t1+b[i];
    }
    if (t1!=0)
        if (t2>0)
            printf("%lld+%lldi\n",t1,t2);
        else if(t2==0) printf("%lld\n",t1);
        else printf("%lld%lldi\n",t1,t2);
    else if(t2==0)printf("0\n");
    else printf("%lldi\n",t2);

    return 0;
}
