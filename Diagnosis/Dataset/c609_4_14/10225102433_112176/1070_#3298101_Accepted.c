#include <stdio.h>
int check(int num,int n)
{
    for(int i = 0;i < n-2;i++)
    {
        int sig = 0;
        if((num&1) == 1)
            if(((num>>1)&1) == 0)
                if(((num>>2)&1) == 1)
                    sig = 1;
        if(sig)
            return 1;
        num = num>>1;
    }
    return 0;
}

int main()
{
    while(1)
    {
        int n;scanf("%d",&n);
        if(n == -1)
            break;
        int num = 1<<n;
        int cnt = 0;
        for(int i = 0;i < num;i++)
        {
            if(check(i,n))
                cnt++;
        }
        cnt = (int)pow(2,n)-cnt;
        printf("%d\n",cnt);
    }
}