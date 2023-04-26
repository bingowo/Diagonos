#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
char s[101];
int func(int l, int r, int state)
{
    int cnt[6] = { 0 }, i, flag=1;
    for (i = l+1 ;i < r;i++)
    {
        if (s[i] == '(') cnt[0]++;
        else if (s[i] == ')') cnt[1]++;
        else if (s[i] == '[') cnt[2]++;
        else if (s[i] == ']') cnt[3]++;
        else if (s[i] == '{') cnt[4]++;
        else if (s[i] == '}') cnt[5]++;
    }
    if (!(cnt[0] == cnt[1] && cnt[2] == cnt[3] && cnt[4] == cnt[5]))
        flag = 0;
    else
    {
        i = l + 1;
        while (flag != 0 && i != r)
        {
            l = i;                      //新的左边界
            if (state == 1)
            {
                if (s[l] != '{')
                    flag=0;
                else
                {
                    for (;s[i] != '}';i++);
                    flag = func(l, i, 3);
                }
            }
            else if (state == 2)
            {
                if (s[l] != '(')
                    flag = 0;
                else
                {
                    for (;s[i] != ')';i++);
                    flag = func(l, i, 1);
                }
            }
            else if (state == 3)
            {
                if (s[l] != '[')
                    flag = 0;
                else
                {
                    for (;s[i] != ']';i++);
                    flag = func(l, i, 2);
                }
            }
            i++;
        }
    }
    return flag;
}
int main()
{
    int T, state;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%s", s);

        if (s[0] == '(') state = 1;
        else if (s[0] == '[') state = 2;
        else if (s[0] == '{') state = 3;

        if (s[0] != '(' && s[0] != '[' && s[0] != '{')
            printf("No\n");
        else if (func(0, strlen(s)-1, state))
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
