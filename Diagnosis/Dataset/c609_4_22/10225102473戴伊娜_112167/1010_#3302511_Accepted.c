#include <stdio.h>

int main()
{
    int t,n;
    scanf("%d%d",&n,&t);
    int a[100];
    char s[100];
    int i,q;
    if(n==0)
        {
            printf("0");
            return 0;
        }
    for(i=0;n!=0;i++)
    {
        if(n%t<0)
        {
            a[i]=n%t-t;
            n=n/t+1;
        }
        else
        {
            a[i]=n%t;
            n=n/t;
        }
        if(a[i]>=0&&a[i]<=9)
            s[i]=a[i]+'0';
        else
            s[i]=a[i]-10+'A';
    }
    for(q=i-1;q>=0;q--)
        printf("%c",s[q]);
    return 0;
}
