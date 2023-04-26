#include <stdio.h>
#include <stdlib.h>

void jzzh(int n,int r)
{
    if(n<0)
    {
        n=-n;
        printf("-");
    }

    int a[1005]= {0};
    int cnt=0;

    while(n!=0)
    {
        a[cnt++]=n%r;
        n=n/r;
    }

    for(int j=cnt-1; j>=0; j--)
    {
        if(a[j]<=9) printf("%d",a[j]);
        else printf("%c",'A'+a[j]-10);
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0; i<T; i++)
    {
        int N,R;
        scanf("%d %d",&N,&R);

        jzzh(N,R);
        printf("\n");
    }

    return 0;
}

