#include <stdio.h>
#include <stdlib.h>

double polish_exper()
{
    char s[11]={0};
    double f1=0,f2=0;
    scanf("%s",s);
    switch(s[0])
    {
        case'+':f1=polish_exper();f2=polish_exper();return f1+f2;
        case'-':f1=polish_exper();f2=polish_exper();return f1-f2;
        case'*':f1=polish_exper();f2=polish_exper();return f1*f2;
        case'/':f1=polish_exper();f2=polish_exper();return f1/f2;
        default:return atof(s);
    }
}

int main()
{
    int T=0;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        printf("case #%d:\n%.6lf\n",i,polish_exper());
    }
    return 0;
}
