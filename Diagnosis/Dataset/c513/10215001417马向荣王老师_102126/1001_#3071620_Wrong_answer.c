#include<stdio.h>
int main()
{
    int t;
    int n,r;
    int i,count,p,j=0;
    char a[128];
    scanf("%d\n",&t);
    while(scanf("%d %d",&n,&r)!=EOF)
    {
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
            if(a[i]>=10)
            {
                if(i!=1) printf("%c",a[i]+55);
                else {
                    printf("%c\n",a[i]+55);
                    i=0;
                }
            }
            else
            {
                if(i!=1) printf("%d",a[i]);
                else {
                    printf("%d\n",a[i]);
                    i=0;
                }
            }
        }
    }
    return 0;
}