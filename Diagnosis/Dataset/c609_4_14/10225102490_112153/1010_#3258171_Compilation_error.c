#include <stdio.h>
#include <stdlib.h>
char ans[50];
int main()
{
    int N,R;
    int cnt = 0;
    do 
    {
        x = N%R;
        N /= R;
        if (x < 0)
        {
            x -=R;
            N++;
        }
        if (x >= 0 && x <= 9) ans[++cnt] = x + '0';
        else ans[++cnt] = x - 10 + 'A';
    } while (N != 0);
    for (int i = cnt; i >= 0; i--)
    {
        printf("%c",ans[i]);
    }
    return 0;
}