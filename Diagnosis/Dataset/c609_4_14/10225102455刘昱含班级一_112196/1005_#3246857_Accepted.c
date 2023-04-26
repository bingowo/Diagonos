#include<stdio.h>
int main()
{
    int t, ans, i, c;
    char s[50];
    scanf("%d\n", &t);
    for(int k = 0; k < t; k++)
    {
        ans = 0;
        for (i = 0; (c = getchar()) != '\n' ; i++) s[i] = c;
        s[i] = '\0';
        for(i = 0; s[i]; i++)
        {
            if (s[i] == '-')
            {
                ans = ans * 3 -1;
            }
            else ans = ans * 3 + s[i] - '0';
        }
        printf("case #%d:\n", k);
        printf("%d\n", ans);
    }
}
