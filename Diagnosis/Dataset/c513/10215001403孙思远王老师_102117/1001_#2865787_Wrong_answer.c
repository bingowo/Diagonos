#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,t,n,r,m;
    int num=0,po=1;
    int flag=0;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        scanf("%d %d",&n,&r);
        if(n<0){flag=1;n=-n;}
        while(n!=0)
        {
            if(n>=r)
            {m=n%r;
            n/=r;}
            else{m=n;n=0;}
            num+=po*m;
            po*=10;
        }
        if(flag)printf("-");
        printf("%d",num);
        printf("\n");
    }
    return 0;
}
