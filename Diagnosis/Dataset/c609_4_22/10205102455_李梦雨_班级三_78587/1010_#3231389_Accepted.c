#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,r;
    scanf("%d%d",&n,&r);
    int a[1000];
    int cnt=0;
    if(n==0) printf("0\n");
    while(n)
    {
        if(n%r>=0)
        {
            a[cnt]=n%r;
            n/=r;
        }
        else
        {
            a[cnt]=n%r-r;
            n=n/r+1;
        }
        cnt++;
    }
    for(int i=cnt-1;i>=0;i--)
    {
        if(a[i]>9)
        {
            char c=a[i]-10+'A';
            printf("%c",c);
        }
        else printf("%d",a[i]);
    }
    printf("\n");
    return 0;
}