#include<stdio.h>
int main()
{
    int t;
    int n,r;
    int i,count,j=0;
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
        }
        count=j;
        for(;j>0;j--)
        {
            if(a[j]>=10) a[j]+=55;
        }
        for(;count>1;count--)
        {
            printf("%c",a[count]);
        }
        printf("%c\n",a[count]);
    }
    return 0;
}