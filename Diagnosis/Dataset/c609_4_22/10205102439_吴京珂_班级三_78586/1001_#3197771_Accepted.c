#include <stdio.h>
#include <stdlib.h>

void _10toR(int n,int r)
{
    if(n<0)//负数
    {
        n=-n;
        printf("-");
    }

    int a[100]= {0};
    int i=0,j=0;
    while(n!=0)
    {
        a[i]=n%r;
        n/=r;
        i++;
    }

    for(j=i-1; j>=0; j--)
    {
        if(a[j]>9) printf("%c",a[j]+55);
        else printf("%d",a[j]);
    }
    printf("\n");
}

int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0; i<t; i++)
    {
        int n,r;
        scanf("%d %d",&n,&r);

        _10toR(n,r);
    }

    return 0;
}
