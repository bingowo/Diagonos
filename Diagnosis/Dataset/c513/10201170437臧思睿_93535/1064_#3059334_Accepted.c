#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double exp()
{
    char s[15];
    memset(s,0,sizeof(char));
    scanf("%s",s);
    switch(s[0])
    {
        case'+':return exp()+exp();
        case'-':return exp()-exp();
        case'*':return exp()*exp();
        case'/':return exp()/exp();
        default:return atof(s);
    }
}
int main()
{
    int t=0,T;
    scanf("%d",&T);
    while(t++<T)
    {
        printf("case #%d:\n",t-1);
        printf("%.6lf\n",exp());
    }
    return 0;
}

