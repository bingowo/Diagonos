#include <stdio.h>
#include<stdlib.h>
int main()
{
    int t;
    int c;
    int j;
    int tmp;
    int cnt = 0;
    long long ans;
    char s[60];
    int alpha[128];

    scanf("%d\n", &t);
    for (int i = 0; i < t; i++)
    {
        ans = 0;
        for (int k = 0; k < 128; k++) alpha[k] = -1;

        for(j = 0; (c = getchar()) != '\n'; j++)
        {
            s[j] = c;
            alpha[c] = 1;
        }
        s[j] = '\0';
        for (int k = 0; k < 128; k++)
        {
            if(alpha[k] != -1) {cnt++;}
        }
        for (int k = 0; s[k]; k++)
        {
            ans = ans * cnt + alpha[s[k]];
        }

        printf("case #%d:\n",i);
        printf("%lld\n",ans);
    }

}
