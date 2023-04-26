#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int judge(int n)
{
    char s[11] = {'\0'};
    char *ps = s;
    itoa(n, ps, 10);
    char temp[11] = {'\0'};
    char *pt = temp;
    for (int i = 0; i < strlen(s); i++)
    {
        temp[i] = s[strlen(s) - 1 - i];
    }

    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] != temp[i])
            return atoi(temp);
    }
    return atoi(s);
}
void fca(int n, int step)
{
    int temp = judge(n);
    if (temp == n)
    {
        printf("%d %d", step, n);
    }
    else
    {
        fca(n + temp, step + 1);
    }
}
int main()
{
    int T;
    int step = 0;
    scanf("%d", &T);
    fca(T, step);
}