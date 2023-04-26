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

    //while(a[i-1]!=0&&i>=0)
    for(int j=i-1;j>=0;j--)
    {
        if(a[j]<10) printf("%d",a[j]);
        else printf("%c",a[j]+'A'-10);

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
