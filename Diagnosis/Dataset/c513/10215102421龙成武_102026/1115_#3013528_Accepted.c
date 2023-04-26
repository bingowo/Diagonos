#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    int x, T, i,j,k, len,maxpos,lpos,rpos,maxc;
    char s[100], * p, c;
    scanf("%d", &T);
    for (x = 0;x < T;x++)
    {
        printf("case #%d:\n", x);
        s[0] = '0';
        scanf("%s", s + 1);
        len = strlen(s);
        rpos = len;              //右下标初始也要设置为一个超出范围的值，因为len-1也是合法的
        lpos = -1;              //因为0下标是合法的，所以要设置为-1
        for (i = len - 1;i > -1;i--)
        {
            for (j = len - 1;j > i;j--)
            {
                if (s[j] > s[i])
                {
                    lpos = i;
                    if (rpos == len)  
                        rpos = j;
                    else if (s[j] < s[rpos])           //原值小
                    {
                        rpos = j;
                    }
                    else if (s[j] == s[rpos])      //原值相同--原下标小（位权大）
                    {
                        if (j < rpos)
                        {
                            rpos = j;
                        }
                    }
                }
            }
            if (lpos != -1)                 //某一次迭代完成后，找到了合适的右/左下标
            {
                c = s[lpos];
                s[lpos] = s[rpos];
                s[rpos] = c;
                break;
            }
        }
        
        
        //此前是右大换左小，现在完成了，则要让值尽可能小，需要右小换左大
        //每一位都要操作
        for (i = lpos + 1;i < len;i++)
        {
            lpos = -1;                    //用lpos来记录有没有在右侧找到合适的比较小的数字
            rpos = len;
            for (j = len - 1;j > i;j--)
            {
                if (s[j] < s[i])
                {
                    lpos = i;
                    if (rpos == len)
                        rpos = j;
                    else if (s[j] < s[rpos])           //原值小
                    {
                        rpos = j;
                    }
                    else if (s[j] == s[rpos])      //原值相同--原下标大（位权小），因为要在尽量占比小的地方换一个大数字
                    {
                        if (j > rpos)
                        {
                            rpos = j;
                        }
                    }
                }
            }
            if (lpos!=-1)
            {
                c = s[lpos];
                s[lpos] = s[rpos];
                s[rpos] = c;
            }
        }
        p = s;
        while (*p == '0') p++;
        puts(p);
    }
    return 0;
}