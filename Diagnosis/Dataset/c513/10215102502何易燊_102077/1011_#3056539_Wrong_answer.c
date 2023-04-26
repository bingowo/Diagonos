#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n;
    scanf("%x",&n);
    int stack[64]; int m = 0;
    do
    {
        stack[m++] = n&1;
        n >>= 1;
    } while (n>0);
    int R = 0, I = 0;
    do
    {
        m--;
        if (stack[m]&1)
        {
            int copyR = 1-(R+I), copyI = R-I;
            R = copyR, I = copyI;
        }
        else
        {
            int copyR = -(R+I), copyI = R-I;
            R = copyR, I = copyI;
        }
    } while (m>0);
    if (R==0&&I==0) printf("0\n");
    else if (R==0&&I==1) printf("i\n");
    else if (R==0&&I==-1) printf("-i\n");
    else if (R==0) printf("%di\n",I);
    else if (R!=0&&I>0) printf("%d+%di\n",R,I);
    else  printf("%d%di\n",R,I);
    return 0;
}