#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T,a,b,cnt,maxa;
    scanf("%d",&T);
    int n[T];
    for(int j=0;j<T;j++)
    {
        scanf("%d",&n[j]);
    }
    for(int i=0;i<T;i++)
    {
        printf("case #%d:\n",i);
        b=n[i]%2;
        n[i]=n[i]/2;
        cnt=1;
        maxa=1;
        while(n[i]>0)
        {
            a=b;
            b=n[i]%2;
            if(a!=b)
                cnt=cnt+1;
            else
                cnt=1;
            if(cnt>maxa)
                maxa=cnt;
            n[i]=n[i]/2;
        }
        printf("%d\n",maxa);
    }
    return 0;
}
