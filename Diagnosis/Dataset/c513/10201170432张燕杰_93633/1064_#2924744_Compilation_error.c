#include<stdio.h>
#include<stdlib.h>

double Poland()
{
    double ans;
    char s[10];
    double Left,Right;
    scanf("%s",s);
    switch(s[0])
    {
        case '+':Left = Poland();Right = Poland();return Left+Right;
        case '-':Left = Poland();Right = Poland();return Left-Right;
        case '*':Left = Poland();Right = Poland();return Left*Right;
        case '/':Left = Poland();Right = Poland();return Left/Right;
        default: return atof(ans);
    }
}

int main()
{
    printf("%.6lf",Poland());
    return 0;
}