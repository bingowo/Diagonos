#include <stdio.h>
#include <stdlib.h>

void jzzh(int n,int r)
{
    if(n<0)
    {
        printf("-");
        n=-n;
    }

    int a[1005]= {0};
    int i=0;
    while(n!=0)
    {
        a[i]=n%r;
        n=n/r;
        i++;
    }

    while(i>0)
    {
        if(a[i-1]<10) printf("%d",a[i-1]);
        else printf("%c",a[i-1]+'A'-10);
        --i;
    }
    printf("\n");
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
    }

    return 0;
}
