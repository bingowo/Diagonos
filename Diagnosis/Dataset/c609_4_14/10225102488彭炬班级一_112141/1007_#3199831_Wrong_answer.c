#include <stdio.h>

int main()
{
    int T;
    scanf("%d",&T);
    for(int d=0;d<T;d++)
    {
        long long int a[10000],b[10000];
        int N;
        scanf("%d",&N);
        for(int f=0;f<N;f++)
            b[f]=0;
        int j=0;
        while(j<N)
        {
            scanf("%lld",&a[j]);
            for(int i=0;i<64;i++)
                if(a[j]&(1<<i))
                b[j]++;
            j++;
        }
        for(int x=0;x<N;x++)
        {
            for(int y=0;y<(N-x);y++)
            {
                if(b[x]<b[x+y])
                {
                    long long int r;
                    r=a[x];
                    a[x]=a[x+y];
                    a[x+y]=r;
                    long long int s;
                    s=b[x];
                    b[x]=b[x+y];
                    b[x+y]=s;
                }
                else if(b[x]==b[x+y])
                    if(a[x]>a[x+y])
                    {
                        long long int r;
                        r=a[x];
                        a[x]=a[x+y];
                        a[x+y]=r;
                        long long int s;
                        s=b[x];
                        b[x]=b[x+y];
                        b[x+y]=s;
                    }
                else continue;
            }
        }
        printf("case #%d:\n",d);
        for(int e=0;e<N;e++)
            printf("%lld ",a[e]);
        printf("\n");
    }
    return 0;
}
