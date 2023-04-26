#include <stdio.h>

main()
{
    int n;
    scanf("0x%X",&n);
    int stack[100] = {0};
    int m = 0;
    do
    {
        stack[m++] = n&1;
        n >>= 1;
    } while (n>0);
    int r=0, i=0, a=0, b=0, c=-1, d=1;
    while (m>0)
    {
        r = a*c-b*d+stack[--m];
        i = a*d+b*c;
        a = r, b = i;
    }
    if (i==0) printf("%d",r);
    else if (i==1||i==-1) printf("%d%ci",r,i>0?'+':'-');
    else printf("%d%c%di",r,i>0?'+':'-',i>0?i:-i);
    return 0;
}