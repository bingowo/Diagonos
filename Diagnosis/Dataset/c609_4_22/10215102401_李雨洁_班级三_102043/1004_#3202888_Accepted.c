#include <stdio.h>
#include <string.h>
#include <math.h>
void itob(int n, int r, char s[])//把十进制n转r进制结果存入s
{
    const char table[] = { "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ" };
    int sigh = 1, m = 1;
    if (n < 0)
    {
        sigh = -1;
        n = -n;
    }  //把负数变为正数
    s[0] = table[n % r];
    n = n / r;
    int id = 0;
    while (n)
    {
        s[id + m] = table[n % r];
        n = n / r;
        m += 1;
    }//一步步求余转化为r进制
    if (sigh == -1)
    {
        s[id + m] = '-';
        s[id + m + 1] = 0;//0即为'\0'
        for (int i = 0; i < m / 2 + 1; i++)
        {
            int t = s[id + i];
            s[id + i] = s[id + m - i];
            s[id + m - i] = t;
        }//for循环调转s
    }
    else
    {
        s[id + m] = 0;
        for (int i = 0; i < m / 2; i++)
        {
            int t = s[id + i];
            s[id + i] = s[id + m - i - 1];
            s[id + m - i - 1] = t;
        }
    }
}
int F(int a,char s[])
{
    int i = 0, j = 0, num = 0, sum = 0, len = 0; 
    while ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9'))
    {
        len++;i++;
    } 
    i = 0;
    while (s[i] != '\0')
    {
        if (s[i] >= '0' && s[i] <= '9')
            num = s[i] - '0';
        else if (s[i] >= 'a' && s[i] <= 'f')
            num = s[i] - 'a' + 10;
        else if (s[i] >= 'A' && s[i] <= 'F')
            num = s[i] - 'A' + 10;
        else
            break;
        for (j = 0; j < len - 1; j++)
            num = num * a;
        sum += num;
        i++;
        len--;
    }
    return sum;
}

int main()
{
    int a, b;
    char s0[1000];
    scanf("%d",&a);
    scanf("%s", s0);
    scanf("%d", &b);
    int mm = F(a, s0);
    char s[1000] = { 0 };
    itob(mm, b, s);
    printf("%s\n", s);
    return 0;
}
