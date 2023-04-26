#include <stdio.h>

int main()
{
    int count,count1;
    scanf("%d",&count);
    count1=count;
    while(count--)
    {
        int m=1, n=1, large=1, small=1, i=1;
        unsigned long long P=1;
        scanf("%d %d",&m,&n);
        if (m>2*n) {small=n; large=m-n;}
        else {small=m-n; large=n;}
        for(int i=m;i>large;i--)
        {
            if(i==2*small)
            {
                P=P*2;
                small--;
            }
            else
            P=P*i;
        }
        while(small>1)
        {
            P=P/small;
            small--;
        }
        printf("case #%d:\n",count1-count-1);
        printf("%lld\n", P);
    }

}
