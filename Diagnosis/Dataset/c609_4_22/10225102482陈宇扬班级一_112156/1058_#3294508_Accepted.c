#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    char s[1005];
    scanf("%s", s);
    int flag = 1;//符号
    if(s[0] == '-') flag = -1;
    int len = strlen(s);

    int num[1005], cnt = 0;
    for(int i = len -1; i >= 0;i--)
    {
        if(s[i] == '-')
            break;
        num[++cnt] = s[i] - '0';
    }

    int ans[1005], aslen = 0;
    while(cnt)
    {
        if(num[1] % 2 == 1)
        {
            if(flag == -1) num[1]++;
            else num[1]--;
            ans[++aslen] = 1;
        }else ans[++aslen] = 0;
        for(int i = cnt; i; i--)
        {
            num[i-1] += 10*(num[i]%2);
            num[i] /= 2;
        }
        while(cnt > 0 && num[cnt] == 0) cnt--;
        flag *= -1;
    }

    for(int i = aslen; i;i--)
    {
        printf("%d", ans[i]);
    }
    return 0;
}
