
#include<stdio.h>
#include<stdlib.h>
typedef long long int lli;
long long int map[75];
lli T(int n)
{
    lli ret;
    if(n==0)
    {
        ret=0;
        map[n]=ret;
    }
    else if(n==1||n==2)
    {
        ret=1;
        map[n]=1;
    }
    else
    {
        if(map[n]!=0)
        {
            ret=map[n];
        }
        else
        {
            ret=T(n-1)+T(n-2)+T(n-3);
            map[n]=ret;
        }
    }
    return ret;

}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        int n;
        scanf("%d",&n);
        lli ret;
        ret=T(n);
        printf("case #%d:\n",i);
        printf("%lld\n",ret);

    }
    return 0;
}
