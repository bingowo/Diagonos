#include<stdio.h>

double expr()
{
    char a[10];
    double f1,f2;
    scanf("%s",a);
    switch(a[0])
    {
        case '+' :   
            
                f1 = expr();
                f2 = expr();
                return f1+f2;
            
        case '-' :   
            
                f1 = expr();
                f2 = expr();
                return f1-f2;
            
        case '*' :   
            
                f1 = expr();
                f2 = expr();
                return f1*f2;
            
        case '/' :   
            
                f1 = expr();
                f2 = expr();
                return f1/f2;
            
        default :
            return atof(a);
    }
}

int main()
{
    int T;double ans=0;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        printf("case #%d:\n",i);
        
        printf("%.6lf\n",expr());
    }
    return 0;
}
