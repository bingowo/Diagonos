#include<stdio.h>
#include<stdlib.h>

double Poland()
{
    char s[10] = {'\0'};
    double Left,Right;
    scanf("%s",s);
    switch(s[0])
    {
        case '+':Left = Poland();Right = Poland();return Left+Right;
        case '-':Left = Poland();Right = Poland();return Left-Right;
        case '*':Left = Poland();Right = Poland();return Left*Right;
        case '/':Left = Poland();Right = Poland();return Left/Right;
        default: return atof(s);
    }
}

int main()
{
    int N;
    scanf("%d",&N);
    for(int i =0;i<N;i++)
    {
        printf("case #%d:\n",i);
        printf("%.6lf\n",Poland());
    }

    return 0;
}
