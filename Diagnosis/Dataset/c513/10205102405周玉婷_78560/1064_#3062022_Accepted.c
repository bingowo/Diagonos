#include <stdio.h>
#include <stdlib.h>
typedef struct{
    double num;
    char sign;
} divisor;
divisor* tail;
void judge(double x)
{
   if((tail->sign) == 0)//栈顶是数字，运算，将运算结果储存
   {
    double temp = (tail->num);
    tail--;
    switch(tail->sign)
    {
        case '+':
        tail->num = temp + x;
        break;
        case '-':
        tail->num = temp - x;
        break;
        case '*':
        tail->num = temp * x;
        break;
        case '/':
        tail->num = temp / x;
        break;
    }
    tail->sign = 0;
    if((tail-1)->sign == 0)
    {
        x = tail->num;
        tail--;
        judge(x);
    }
   }
   else {++tail; (tail->num) = x; (tail->sign) = 0;}//栈顶是运算符，暂不运算，数字储存起来
   return ;
}

int main()
{
    int t;
    scanf("%d", &t);
    char c;
    c = getchar();
    divisor* p = (divisor*)malloc(sizeof(divisor)*60);
    tail = p;
    for(int j=0; j<t; j++)
    {
        char s[12];
        int index = 0;
        c = getchar();
        tail->sign = c;
        while( c!='\n' )
        {
        c = getchar();
        if(c == ' ') continue;
        else if(c == '*' || c == '+' || c == '-' || c == '/')  {++tail; tail->sign = c;}
        else
        {
            do{s[index++] = c;}
            while((c=getchar()) != ' ' && c!='\n');
            s[index] = '\0';
            double num = atof(s);
            judge(num);   
            index = 0;
        }
        }
        printf("case #%d:\n", j);
        printf("%.6lf\n", tail->num);
    }
    tail = 0;
    free(p);
    return 0;
}