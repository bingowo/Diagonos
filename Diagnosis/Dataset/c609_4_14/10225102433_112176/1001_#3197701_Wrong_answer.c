#include <stdio.h>
#include <string.h>
#include <math.h>

char s[16] = "0123456789ABCDEF";

void solve(int num,int n)
{
    if(n >= 16)
        n = 16;
    if(n > abs(num))
    {
        printf("\n");
        return;
    }
    char p[100] = {0};
    int cnt = 0;
    if(num < 0)
    {
        printf("-");
        num = -num;
    }

    while(num)
    {
        p[cnt++] = s[num%n];
        num /= n;
    }
    for(int i = strlen(p)-1;i >= 0;i--)
    {
        printf("%c",p[i]);
    }
    printf("\n");
}
int main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        solve(a,b);
    }

    return 0;
}