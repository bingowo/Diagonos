#include <stdio.h>
#include <string.h>
int main()
{
    int T;
    scanf("%d", &T);
    int cnt = 0;
    while(cnt < T)
    {
        int n;
        scanf("%d", &n);
        int s[32];
        int len = 0;
        int max = 1;
        if(n == 0) max = 1;
        while(n > 0)
        {
            s[len++] = n % 2;
            n = n / 2;
        }
        for(int i = 0; i < len - 1;i++)
        {
            int j = i + 1;
            int sum = 1;
            if(s[i] != s[j]) {sum = 2;i++;j++;}
            while(s[i] != s[j] && j < len)
            {
                sum++;
                i++;
                j++;
            }
            max = (sum > max)?sum:max;
        }
        printf("case #%d:\n", cnt);
        printf("%d\n",max);
        cnt++;
    }
}