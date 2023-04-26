#include<stdio.h>
int main()
{
    int t;//组数
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        char s[61];
        scanf("%s",&s);
        printf("case #%d:\n",i);
        f(s);
    }
    return 0;
}

void f(char s[61])
{
    int num[128];
    for (int i = 0; i < 128; i++) num[i] = -2;
    int cnt = 0;
    char* p = s;
    num[*p] = 1;//首位表示1
    while (*++p)
    {
        if (num[*p] == -2)
        {
            num[*p] = cnt;
            cnt = cnt ? cnt + 1 : 2;
        }
    }
    if (cnt < 2) cnt = 2;//不可能1进制
    long long ans = 0;
    p = s;
    while (*p!=-2) ans = ans * cnt + num[*p++];
    printf("%lld\n", ans);
}
