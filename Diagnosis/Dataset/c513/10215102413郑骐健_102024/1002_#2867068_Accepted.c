#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdio.h>
#include<string.h>
#include<stdlib.h>

int cmp(char* p1, int length, char p2)
{
    for (int i = 0;i < length;i++)
    {
        if (*(p1 + i) == p2)
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    int T;
    int n;
    scanf("%d", &T);

    for (int i = 0;i < T;i++)
    {
        char s[200];
        char all[65];
        int flag = 0;//特判1111的情况
        int a[200];//记录字符存储的值
        int R = 0;//进位数
        char* p = s;
        scanf("%s", &s);
        int length = 0;

        for (int j = 0;j < strlen(s) ;j++)
        {
        if (cmp(all, R, *(p+j)))
                    {
                        all[R] = *(p+j);
                        if (R == 0)a[all[R]] = 1;
                        else if (R == 1) a[all[R]] = 0;
                        else a[all[R]] = R;
                        R++;
                    }
        }
        if (R == 1)R = 2;

        long long int res = 0;
        for (int j = 0;j < strlen(s);j++)
        {
            res *= R;
            res += a[s[j]];
        }
        printf("case #%d:\n%lld\n", i, res);
    }
    return 0;

}
