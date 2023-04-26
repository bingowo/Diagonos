#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int divi(int a, int b)
{
    int div = 0;
    while (a % b)
    {
        div = a % b;
        a = b;
        b = div;
    }
    div = b;
    return div;
}

int main()
{
    int n;
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; i++)
    {
        char s[121];
        gets(s);
        int sizes = strlen(s);
        int cnt = 0;
        int sizen = sizes * 8; //都是字符串，1个char=8位二进制数
        for (int j = 0; j < sizes; j++)
        {
            while (s[j])
            {
                s[j] = s[j] & (s[j] - 1);
                cnt++; //算1的个数,即分子
            }
        }
        int sum = divi(sizen, cnt);
        printf("%d/%d\n", cnt / sum, sizen / sum);
    }
    system("pause");
    return 0;
}
