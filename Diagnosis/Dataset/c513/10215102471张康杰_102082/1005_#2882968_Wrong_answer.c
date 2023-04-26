#include <stdio.h>
#include <stdlib.h>
#include <string.h>
double mypow(double x,int y)
{
    double output = 1;
    int i;
    for(i = 0;i < y;i++)
        output *= x;
    return output;
}
int main()
{
    int T, i;
    scanf("%d",&T);
    for(i = 0;i < T;i++)
    {
        int n;
        double output = 0;
        char input[52];
        scanf("%s",input);
        for(n = 2;n < strlen(input);n++)
        {
            output += (input[n] - '0')*mypow(0.125,n-1);//可能时pow函数出错
            //printf("%d",*pt - '0');
        }
        int accuracy = 3*(n - 2);
        printf("case #%d:\n%.*lf\n",i,accuracy,output);
    }
    return 0;
}
//
