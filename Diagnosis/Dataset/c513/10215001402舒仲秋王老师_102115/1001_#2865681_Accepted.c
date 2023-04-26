#include <stdio.h>
#include <stdlib.h>
void backString(char s[])
{
    int i, l = strlen(s), temp;
    for (i = 0; i <= l / 2 - 1; i++)
    {
        temp = s[i];
        s[i] = s[l - i - 1];
        s[l - i - 1] = temp;
    }
}

void itob(int n, char s[100], int b)
{
    int flag = 0, i = 0;
    if (n < 0)
        flag = 1, n = -n;//负数的情形用flag标记
    while (n > 0)
    {
        if (n % b < 10)
            s[i++] = '0' + n % b;//当结果在10以内时用数字输出
        else
            s[i++] = 'A' + n % b - 10;
        n = n / b;
    }
    s[i] = '\0';//即逆序输出后的末尾添加\0
    if (flag == 1)
    {
        s[i] = '-';
        s[i + 1] = '\0';
    }
    backString(s);
}

int main()
{
    int n[100], b[100],N,i;
    scanf("%d",&N);
    for(i=0;i<N;i++)
    {
        scanf("%d%d",&n[i],&b[i]);
    }
    for(i=0;i<N;i++)
    {
        char s[100];
        itob(n[i],s,b[i]);
        printf("%s\n",s);
    }
    return 0;
}
