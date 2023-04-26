#include <stdio.h>
char table[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
void trans(int N,int R)
{
    if(N)
    {
        int c=N/R,d=N%R;
        if(d<0)
        {
            c++;
            d=(-R)+d;
        }
        trans(c,R);
        putchar(table[d]);
    }
}
int main()
{
    int N,R;
    scanf("%d%d",&N,&R);
    if(N==0)
        putchar(table[0]);
    trans(N,R);
    printf("\n");
    return 0;
}