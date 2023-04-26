#include <stdio.h>
#include <math.h>
int main()
{
    int T,i,j,m;
    double res;
    char c[50];
    scanf("%d",&T);
    for(i = 0;i<T;i++)
    {
        res = 0;j = 2;
        scanf("%s",c);
        while(c[j]!='\0')
    {
        res = res + (c[j]-'0')*pow(1.0/8,j-1);
        j++;
    }
    m = 3*(j - 2);
    printf("%.*Lf\n",m,res);
    }
    return 0;
}
