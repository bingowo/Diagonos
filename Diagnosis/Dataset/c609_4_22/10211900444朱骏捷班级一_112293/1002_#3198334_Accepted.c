#include <stdio.h>
#include <math.h>

/*
对于一个二进制串 b=bkbk-1…b1，如果对任意 i (1≤i≤k-1)，满足 bi≠bi+1，
那么 b 称为非重复二进制串。给定一个正整数，输出其二进制表示中最长的非重复二进制串的长度。

输入格式
第 1 行：一个整数 (1<=T<=10) 为问题数。

第 2~T+1 行，每行一个十进制表示的正整数 n，(0,2^31)。

输出格式
对于每个问题，输出一行问题的编号（0 开始编号，格式：case #0: 等），
在接下来一行中输出 n 的二进制表示中最长的非重复二进制串的长度（前置 0 不计算在内）。
*/

int nonrev(int num, int len)
{
    int remainder, cnt = 1, i = 0, res = 1;
    char s[len];
    while (len - i)
    {
        remainder = num % 2;
        s[i] = remainder;

        i++;
        num /= 2;
    }
    int temp = 0;
    for (int j = len - 1; j > 0; --j)
    {

        if (s[j] != s[j - 1])
        {
            ++cnt;
            res = cnt;
        }
        else
        {
            temp = res;
            cnt = 1;
        }
        if (temp > res)
            res = temp;
    }
    return res;
}

int main()
{
    int n;
    scanf("%d", &n);
    char ch;
    int arr[n], i = 0;

    while ((ch = getchar()) != EOF)
    {
        int q;
        scanf("%d", &q);
        arr[i] = q;
        ++i;
    }

    int m = 0;
    while (n - m > 0)
    {
        int len = (int)log2(arr[m]) + 1;
        int res = nonrev(arr[m], len);
        printf("case #%d:\n", m);
        printf("%d\n", res);
        ++m;
    }

    return 0;
}