#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t;
    scanf("%d",&t);
    for(int f=0;f<t;f++)
    {
        long long int n;int r;
        scanf("%lld %d",&n,&r);
        int s[210]={0};int p=0;
        while(n)
        {
            s[p++]=n%r;
            n=n/r;
        }
        long long int num=0;
        for(int i=0;i<p;i++) {num+=s[i];}
        p=0;
        while(num)
        {
            s[p++]=num%r;num=num/r;
        }
        printf("case #%d:\n",f);
        if(p>0)
        {
            for(int i=p-1;i>=0;i--)
            {
                if(s[i]<10) printf("%d",s[i]);
                else printf("%c",(s[i]-10)+'A');
            }
        }
        else printf("0");
        printf("\n");
    }
    return 0;
}