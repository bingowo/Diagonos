#include<stdio.h>
#include<math.h>
int main()
{
    int t,n,r,a,b=0,j=0;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        scanf("%d %d",&n,&r);
        if(n<0) a=-n;
        else a=n;
        while(a!=0)
        {
            b=b+a%r*(int)pow(10,j);
            a=a/r;
            j++;
        }
        if(n>0) printf("%d",b);
        else printf("%d",-b);
    }
    return 0;
}