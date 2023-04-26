#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


double stack[100];
int point =0;
void push(double m)
{
    stack[point++]= m;
}
double out()
{
    return stack [--point];
}
int main()
{


    int t;
    scanf("%d",&t);
    for(int i = 0;i<t;i++)
    {
        point =0;
        int n =0;
        char *p[1500];
        char s[100];
        while(scanf("%s",s)!=EOF)
    {
        p[n] = (char*)malloc(sizeof(char)*100);
        strcpy(p[n],s);
        n++;
        char a =getchar();
        if(a=='\n')break;
    }
    double m =0;
    for(int i = n-1;i>=0;i--)
    {
        switch (p[i][0])
        {
        case '+':
            m = out()+out();
            push(m);
            break;
        case '-':
            m = out();
            m = m - out();
            push(m);
            break;
        case '*':
            m = out()*out();
            push(m);
            break;
        case '/':
            m = out();
            m = m/out();
            push(m);
            break;
        default:push(atof(p[i]));
        }
    }
      printf("case #%d:\n",i);
    printf("%.6f\n",stack[0]);
    for(int q =0; q<n;q++)
    {
        free(p[q]);
    }
    }
    return 0;
}
