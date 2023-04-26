#include <stdio.h>
#include <stdlib.h>

double bo(double all)
{
    char s[100];
    double f1,f2;
    scanf("%s",s);
    switch(s[0])
    {
        case '+':f1=bo(all);f2=bo(all);return f1+f2;break;
        case '-':f1=bo(all);f2=bo(all);return f1-f2;break;
        case '*':f1=bo(all);f2=bo(all);return f1*f2;break;
        case '/':f1=bo(all);f2=bo(all);return f1/f2;break;
        default:return atof(s);
    }
}
int main()
{
    int t,T;
    scanf("%d\n",&T);
    for(t=0;t<T;t++)
    {
        printf("case #%d:\n",t);
        double all=0;
        all=bo(all);
        printf("%f\n",all);
    }
    return 0;
}
