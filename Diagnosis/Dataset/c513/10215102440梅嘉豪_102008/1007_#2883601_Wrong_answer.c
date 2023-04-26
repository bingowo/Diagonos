#include <stdio.h>

int main()
{
    int t,ans=1,n;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        scanf("%d",&n);
        int d=1,d2=1,p=0,fd;
        for(;p<32;p++)
        {
            if(d&n)    break;
            d=d<<1;
        }
        if(p==32)
        {
            printf("case #%d:\n%d\n",t,ans);
            break;
        }
        if(p!=0)
        {
            d2=d2<<(p-1);
            if((d&n)==0)  ans++;
        }
        while(p<32)
        {
            fd=d&n;
            d=d<<1;
            p++;
            if((d&n)==fd) break;
            else    ans++;
        }
        printf("case #%d:\n%d\n",i,ans);
    }

}