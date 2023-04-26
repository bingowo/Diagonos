#include <stdio.h>
#include <stdlib.h>

char* convert(int N, int R)
{
    int num = 0;
    char* s = (char*)malloc(32);
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
    num--;
    while(N)
    {
        if(0<= (N%R) && (N%R) <= 9)
        {
            s[num] = N % R + '0';
        }
        else
        {
            s[num] = N % R + 'A' - 10;
        }
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
    for (i = 0; i < T; i++)
    {
        int N = 0;
        int R = 0;
        scanf("%d %d", &N, &R);
        printf("%s\n", convert(N,R));
    }
    return 0;
}
