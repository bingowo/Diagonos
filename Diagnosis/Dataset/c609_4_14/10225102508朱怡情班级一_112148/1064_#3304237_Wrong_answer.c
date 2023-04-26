#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

int main()
{
    int n,m;
    scanf("%d%d",&m,&n);
    int a,b;
    a=n>m?n:m;
    b=n>m?m:n;
    int cnt=a/b;
    printf("%d",4*b*cnt);
    return 0;
}
