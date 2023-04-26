#include <stdio.h>
#include <math.h>
#include <string.h>
int main ()
{
    int ct = 0 ,T;
    scanf("%d",&T);
    int n ;
    int maps[258];
    long long ans, x;
    while (T--)
    {
        scanf("%s",a);
        n = strlen(a);
        x = 0;
        if (n == 1)//处理如果只有一个字符的情况
        {
            printf("case #%d:\n1\n",ct++);
            continue;
        }
        memset(maps, 0, sizeof(maps));
        int sig = -1;
        for (int i = 0; i < n; i++)
        {
            if (sig == -1 && a[i] != a[0]) 
            //如果这是第一次出现跟首位字符不一样的字符，则sig为该字符的下标位置
                sig = i;
            if (maps[a[i]] == 0 && a[i] != a[sig]) 
            //如果这个数还没有出现过，且这个数不等于第二最高项
                maps[a[i]] = ++x;
                //计算进制数
        }
        ans = 0; 
        ++x;//x为位数
        for (int i = 0; i < n; i++)
        {
            ans = ans * x + (long long)maps[a[i]]; 
        }
        printf("case #%d:\n%lld\n",ct++,ans);
        
        
    }
}
