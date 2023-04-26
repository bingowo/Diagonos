#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void BaseChange(int N,int R)
{
    char table[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    if(fabs(N) < fabs(R))
    {
        putchar(table[(int)fabs(N)]);
        return;
    }
    else
    {
        if(N%R <= 0)
        {
            BaseChange(N/R + 1,R);
            putchar(table[(int)fabs(N%R - R)]);
        }
        else
        {
            BaseChange(N/R,R);
            putchar(table[(int)fabs(N%R)]);
        }
    }
}
int main()
{
    int N,R;
    scanf("%d %d",&N,&R);
    BaseChange(N,R);
    putchar('\n');
    return 0;
}
