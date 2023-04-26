#include <stdio.h>
#include <stdlib.h>

double expr()
{
    char s[10];
    scanf("%s",s);
    double f1,f2;
    switch(s[0])
        {
            case'+':{f1=expr();f2=expr();return f1+f2;}
            case'-':{f1=expr();f2=expr();return f1-f2;}
            case'*':{f1=expr();f2=expr();return f1*f2;}
            case'/':{f1=expr();f2=expr();return f1/f2;}
            default: return atof(s);
        }
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        double ans;
        ans=expr();
        printf("case #%d:\n%lf\n",i,ans);
    }
    return 0;              
}