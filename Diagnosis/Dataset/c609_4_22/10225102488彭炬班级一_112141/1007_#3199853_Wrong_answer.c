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
        long long int *p1=a,*p2=b;
        for(int x=0;x<N;x++)
        {
            for(int y=0;y<(N-x);y++)
            {
                if(*(p2+x)<*(p2+x+y))
                {
                    long long int r;
                    r=*(p1+x);
                    *(p1+x)=*(p1+x+y);
                    *(p1+x+y)=r;
                    long long int s;
                    s=*(p2+x);
                    *(p2+x)=*(p2+x+y);
                    *(p2+x+y)=s;
                }
                else if(b[x]==b[x+y])
                    if(a[x]>a[x+y])
                    {
                        long long int r;
                        r=*(p1+x);
                        *(p1+x)=*(p1+x+y);
                        *(p1+x+y)=r;
                        long long int s;
                        s=*(p2+x);
                        *(p2+x)=*(p2+x+y);
                        *(p2+x+y)=s;
                    }
            }
        }
        printf("case #%d:\n",d);
        for(int e=0;e<N;e++)
            printf("%lld ",a[e]);
        printf("\n");
    }
    return 0;
}
