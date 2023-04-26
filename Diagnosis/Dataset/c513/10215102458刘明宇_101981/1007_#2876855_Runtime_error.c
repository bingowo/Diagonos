#include <stdio.h>
#include <string.h>
int main()
{
    int T;
    scanf("%d", &T);
    int cnt = 0;
    while(cnt < T)
    {
        int ans;
        int n;
        scanf("%d", &n);
        int s[32];
        int i = 0;
        //if(n == 0) ans = 0;
        while(n > 0)
        {
            s[i++] = n % 2;
            n = n / 2;
        }
        int max = 0;
        for(int i = 0; i < strlen(s) - 1;i++)
        {
            int j = i + 1;
            int sum = 0;
            while(s[i++] != s[j++] && j < strlen(s))
            {
                sum++;
            }
            max = (sum > max)?sum:max;
        }



        printf("case #%d\n", cnt);
        printf("%d\n",max);
        cnt++;
    }
}
