#include <stdio.h>
#include <stdlib.h>

char* convert(int N, int R)
{
    int num = 0;
    if(N < 0)
    {
        s[0] = '-';
        N = -N;
        num++;
    }
    int n = N;
    while(n)
    {
        num++;
        n /= R;
    }
    while(N)
    {
        s[num] = N % R;
        N = N / R;
        num--;
    }
    return s;
}

int main()
{
    int T = 0;
    scanf("%d", &T);
    int i = 0;
    char s[32] = {0};
    for (i = 0; i < T; i++)
    {
        int N = 0;
        int R = 0;
        scanf("%d %d", &N, &R);
        printf("%s\n", convert(N,R));
    }
    return 0;
}
