#include <stdio.h>
#include <string.h>
int main()
{
    char s[100005], ans[100005];
    scanf("%s", s);
    int len = strlen(s);
    int pos = 0, cnt = 0;
    for (int i = 0; i < len; i++)
    {
        while (pos < len && s[i] == s[pos])
            pos++;
        if (pos < len && s[pos] > s[i])
            ans[cnt++] = s[i];
        ans[cnt++] = s[i];
    }
    ans[cnt] = '\0';
    printf("%s", ans);
    return 0;
}