#include <stdio.h>
#include <string.h>

int n;
int ans[10010];
int tmp[10010];
int lena;

void solve()
{
    ans[lena++] = 1;
    for(int i = 1;i <= n;i++)
    {
        int t = 0;
        for(int j = 0;j < lena;j++)
        {
            t = ans[j]*i+t;
            tmp[j] = t%10;
            t /= 10;
        }
        while(t)
        {
            tmp[lena++] = t%10;
            t /= 10;
        }
        for(int j = 0;j < lena;j++) ans[j] = tmp[j];
        memset(tmp,0,sizeof(tmp));
    }
    int cnt = 0;
    for(int i = 0;i < lena;i++)
    {
        if(ans[i] == 0) cnt++;
        else break;
    }
    printf("%d\n",cnt);
    lena = 0;
}

int main()
{
    int t;scanf("%d",&t);
    for(int i = 0;i < t;i++)
    {
        printf("case #%d:\n",i);
        scanf("%d",&n);
        solve();
    }
    return 0;
}