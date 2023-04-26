#include <stdio.h>
#include <stdlib.h>

void jzzh(int n,int r)
{
    if(n<0)
    {
        printf("-");
        n=-n;
    }

    int a[100]={0};
    int i=0;
    while(n!=0)
    {
        a[i]=n%r;
        n=n/r;
        i++;
    }

    int j=0;
    while(a[j]!=0)
    {
        printf("%d",a[j]);
        j++;
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
