#include<stdio.h>
int f(int x,int y)
{
    int min = (x > y) ? y : x;
    int max = (x > y) ? x : y;
    int end = 0;
    while (max % min)
    {
        int num = max / min;
        end += min * 4 * num;
        int t = min;
        min = max % min;
        max = t;
    }
    return end + max * 4;
}
int main()
{
    int x, y;
    scanf("%d %d", &x, &y);
    printf("%d", f(x, y));
    return 0;
}