#include<stdio.h>
#include<string.h>

int main()
{
    int T,t=0;
    scanf("%d",&T);
    while (T--)
    {
        unsigned int x;
        scanf("%u",&x);
        int i=0,left=0,max=0,count;
        for(i=0;i<31;i++)
        {
            if(x<<i>>31==0) left++;
            else break;
        }
        while (left<31 && i<31)
        {
            count=1;
            for(i=left;i<31;i++)
            {
                if((x<<i>>31)==(x<<(i+1)>>31))
                {
                    left=i+1;
                    break;
                }
                else count++;
            }
            if(count>max) max=count;
        }
        if(x==1) max=0;
        printf("case #%d:\n%lld\n",t,max);
        t++;
    }
    return 0;
}
