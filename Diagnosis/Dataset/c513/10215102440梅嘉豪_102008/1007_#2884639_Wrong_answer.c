#include <stdio.h>
int same_with(int n);
int zero_check(int n);

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
            if(same_with(n))
            {
                if(zero_check(n))   ans-1;
                maxans=maxans>ans?maxans:ans;
                ans=1;
                flag2=1;
            }
            else    ans++;
            printf("%d  ",ans);
            if(zero_check(n))   ans--;
            maxans=maxans>ans?maxans:ans;
            printf("%d\n",ans);
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
int zero_check(int n)
{
    for(int i;i<32;i++)
    {
        n=n>>1;
        if(n&1) return 0;
    }
    return 1;
}