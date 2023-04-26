#include<stdio.h>
int main()
{
    int t;
    int n,r;
    int i,count,p,j=0;
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
        
        for(count=j;count>0;count--)
        {
            if(a[count]>=10) a[count]+=55;
        }
        for(int p=count;p>1;p--)
        {
            printf("%c",a[p]);
        }
        printf("%c\n",a[p]);
    }
    return 0;
}