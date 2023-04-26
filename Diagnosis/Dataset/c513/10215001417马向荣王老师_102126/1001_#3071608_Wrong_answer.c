#include<stdio.h>
int main()
{
    int t;
    int n,r;
    int i,j=0;
    char a[128];
    scanf("%d\n",&t);
    for(i=0;i<t;i++)
    {
        scanf("%d %d",&n,&r);
        if(n<0)
        {
            printf("-");
            n=-n;
        }
        while(n!=0)
        {
            j++;
            a[j]=n%r;
            n/=r;
            if(a[j]>=10) a[j]+=55;
        }
        for(;j>1;j--)
        {
            printf("%c",a[j]);
        }
        printf("%c\n",a[1]);
    }
    return 0;
}