#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
double expr()
{
    char s[10];
    double f1,f2;
    scanf("%s",s);
    switch(s[0])
    {
        case '+':{f1 = expr();f2 = expr();return f1+f2;}//读到符号就读下两个字符串，若下一个字符串是符号则再进行一次符号分支，算出来的数就是这个fi的值
        case '-':{f1 = expr();f2 = expr();return f1-f2;}
        case '*':{f1 = expr();f2 = expr();return f1*f2;}
        case '/':{f1 = expr();f2 = expr();return f1/f2;}
        default:return atof(s);
    }
}


int main()
{
    int n,i;
    scanf("%d",&n);
    for(i = 0; i < n; i++)
    {
        double ans = expr();
        printf("case #%d:\n",i);
        printf("%lf\n",ans);
    }
}