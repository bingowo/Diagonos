#include <stdio.h>

int diff(int x, int y);

int main()
{
    int T;
    scanf("%d", &T);
    int cnt = 0;
    while(cnt < T)
    {
        int x, y;
        scanf("%d %d", &x,&y);
        diff(x, y);
        cnt++;
    }
    return 0;
}

int diff(int x, int y)
{
    int sum = 0;
    int xl[64];
    int yl[64];
    for(int i = 0; i < 64;i++)
    {
        xl[i] = x % 2;
        x = x / 2;
    }
    for(int j = 0; j < 64;j++)
    {
        yl[i] = y % 2;
        y = y / 2;
    }
    for(int k = 0;k < 64;k++)
    {
        if(xl[k] != yl[k]) sum++
    }
    printf("%d\n", sum);
}