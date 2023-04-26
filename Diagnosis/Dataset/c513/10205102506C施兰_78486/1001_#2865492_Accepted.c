#include <stdio.h>
#include <string.h>
#include <math.h>

char s[100], a;
char convert(int m)
{
    return m < 10 ? '0' + m : 'A' + m - 10;
}
int main()
{

    int I;
    scanf("%d", &I);
    for (int i = 0; i <I;i++)
    {
        a = 0;
        int n, r,N;
        scanf("%d%d", &n, &r);
        N = abs(n);
        while (N)
        {
            s[a++] = convert(N % r);
            N /= r;
        }
        if(n<0)
            printf("-");
        for (int k = a-1; k >= 0;k--)
            printf("%c", s[k]);
        printf("\n");
    }
    return 0;
}

