#include <stdio.h>
#include<stdlib.h>
int main()
{
    int t, c, j, tmp;
    int cnt, x;
    long long ans;
    char s[60];
    int alpha[128];

    scanf("%d\n", &t);
    for (int i = 0; i < t; i++)
    {
        ans = 0; x = 2; cnt = 0;
        for (int k = 0; k < 128; k++) alpha[k] = -1;
        for(j = 0; (c = getchar()) != '\n'; j++)
        {
            s[j] = c;
            alpha[c] = -2;
        }
        s[j] = '\0';
        for (int k = 0; k < 128; k++) if(alpha[k] != -1) cnt++;
        if(cnt == 1) cnt = 2;
        alpha[s[0]] = 1;
        for (int k = 1; s[k]; k++)
        {
            if (s[k-1] != s[k])
            {
                alpha[s[k]] = 0;
                tmp = k;
                break;
            }
        }
        for (int k = tmp +1; s[k]; k++)
        {
            if(s[k-1] != s[k] && alpha[s[k]] == -2)
            {
                alpha[s[k]] = x;
                x++;
            }
        }
        for (int k = 0; s[k]; k++)
            ans = ans * cnt + alpha[s[k]];
        printf("case #%d:\n",i);
        printf("%lld\n",ans);
    }

}
