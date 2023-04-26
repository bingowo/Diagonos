#include <stdio.h>
int same_with(int n);

int main()
{
    int t,n;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        scanf("%d",&n);
        int d=1,d2=1,p=0,fd,maxans=1,ans=1,flag=0,flag2=1;
        for(int i=0;i<31;i++)
        {
            if(n&1&&flag2) {flag=1;flag2=0;}
            if(flag)
            {
                if(same_with(n))
                {
                    maxans=maxans>ans?maxans:ans;
                    ans=1;
                    flag=0;
                    flag2=1;
                }
                else    ans++;
                maxans=maxans>ans?maxans:ans;
            }
            n=n>>1;
        }
        printf("case #%d\n%d\n",i,maxans);
    }

}
int same_with(int n)
{
    int fd=1&n;
    n=n>>1;
    if((1&n)==fd) return 1;
    else    return 0;
}
