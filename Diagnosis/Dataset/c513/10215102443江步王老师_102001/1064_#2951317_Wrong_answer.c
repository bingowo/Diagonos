#include<stdio.h>


double expr();

int main()
{
    int T;
    int i;
    scanf("%d",&T);
    getchar();

    for (i=0;i<T;i++)
    {
        printf("case #%d:\n",i);
        printf("%.6lf\n",expr());
    }   
    return 0;
}

double expr()
{
    char a[10];
    double f1,f2;
    scanf("%s",a);

    switch (a[0])
    {
        case '+':
        {
            f1=expr();f2=expr();return f1+f2;
        }
        case '-':
        {
            f1=expr();f2=expr();return f1-f2;
        }
        case '*':
        {
            f1=expr();f2=expr();return f1*f2;
        }
        case '/':
        {
            f1=expr();f2=expr();return f1/f2;
        }
        default:
        return atof(a);
    }

}