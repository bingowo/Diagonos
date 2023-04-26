#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void BaseChange(int x,int y)
{
    char table[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    if((int)fabs(x) < (int)fabs(y))
    {
        putchar(table[(int)fabs(x)]);
        return;
    }
    else
        BaseChange(x%y,y);
    putchar(table[(int)fabs(x%y)]);

}
int main()
{
    int N,R;
    scanf("%d %d",&N,&R);
    char table[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    BaseChange(N,R);
    putchar('\n');
    return 0;
}
