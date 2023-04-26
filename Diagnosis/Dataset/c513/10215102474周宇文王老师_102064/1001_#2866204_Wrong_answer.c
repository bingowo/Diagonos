#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T,t,a[10000],b[10000],i=0,m;
    char c[10000][10000];
    scanf("%d",&T);
    t = 0;
    while(t<T)
    {
        scanf("%d%d",&a[t],&b[t]);
        t++;
    }
    for(t=0;t<T;t++)
    {
        i = 0;
        while(a[t]!=0)
        {
            if(a[t]%b[t]<10)
                {c[t][i]=a[t]%b[t];}
            else
                {
                    c[t][i] = a[t]%b[t]-10 +'A';
                }

            a[t] = a[t]/b[t];
            i++;
        }
        for(m=i-1;m>=0;m--)
        {
            printf("%d",c[t][m]);
        }
        printf("\n");
    }

    return 0;
}