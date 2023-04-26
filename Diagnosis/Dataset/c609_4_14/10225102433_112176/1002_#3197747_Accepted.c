#include <stdio.h>

void solve(int n)
{
    int res = n&1,max = 0,cnt = 1;
    while(n)
    {
        if((n>>1) == 0)
            break;
        int r2 = (n>>1)&1;
        if(res != r2)
        {
            cnt++;
            res = r2;
        }
        else
        {
            max = max > cnt ? max : cnt;
            cnt = 1;
        }
        n = n>>1;
    }
    max = max > cnt ? max : cnt;
    printf("%d\n",max);
}

int main()
{
    int n;scanf("%d",&n);
    for(int i = 0;i < n;i++)
    {
        printf("case #%d:\n",i);
        int num;
        scanf("%d",&num);
        solve(num);
    }
    return 0;
}