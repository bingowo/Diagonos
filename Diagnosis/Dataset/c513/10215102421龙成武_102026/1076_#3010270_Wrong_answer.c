#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
char s[101];
int getstate(char c)
{
    int state;
    if (s[0] == '(') state = 1;
    else if (s[0] == '[') state = 2;
    else if (s[0] == '{') state = 3;
    else state = -1;
    return state;
}
int func(int l, int r, int state)
{
    int cnt[6] = { 0 }, i, flag=1;
    for (i = l ;i < r+1;i++)                //开头和结尾的字符也要算进去，因为有可能会有()[]这样的
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
        //i = l + 1;
        l++;//新的左边界
        while (flag != 0 && l != r)
        {
            //l = i; 
            i = l;
            if (state == -1)
                flag = 0;
            else if (state == 1)
            {
                if (s[l] == ')')
                {
                    l++;
                    state = getstate(s[l]);
                }
                else if (s[l] != '{')
                    flag=0;
                else                    //如果不是啥也没包进去，就说明包含的第一个元素一定是{
                {
                    for (;s[l] != '}';l++);
                    flag = func(i, l, 3);
                }
            }
            else if (state == 2)
            {
                if (s[l] == ']')
                {
                    l++;
                    state = getstate(s[l]);
                }
                else if (s[l] != '(')
                    flag = 0;
                else
                {
                    for (;s[l] != ')';l++);
                    flag = func(i, l, 1);
                }
            }
            else if (state == 3)
            {
                if (s[l] == '}')
                {
                    l++;
                    state = getstate(s[l]);
                }
                else if (s[l] != '[')
                    flag = 0;
                else
                {
                    for (;s[l] != ']';l++);
                    flag = func(i, l, 2);
                }
            }
            l++;
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
        state = getstate(s[0]);
        if (func(0, strlen(s)-1, state))
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
