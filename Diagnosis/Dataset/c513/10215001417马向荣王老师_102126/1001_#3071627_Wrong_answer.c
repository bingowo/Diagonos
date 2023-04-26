#include<stdio.h>
int main()
{
    int t;
    int n,r;
    int i,count,p,j=0;
    char a[1000];
    scanf("%d\n",&t);
    while(scanf("%d %d",&n,&r)!=EOF)
    {
        j=0;
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
        for(int i=j;i>0;i--)
        {
            if(a[i]>=10) a[i]+=55;
            printf("%c",a[i]);
        }
    }
    return 0;
}