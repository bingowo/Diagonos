#include <stdio.h>
#include <stdlib.h>
double pow(double x, double y)
{
    double output = 0;
    if(y < 0)
    {
        y = -y;
        x = 1/x;
    }
    int i = 0;
    for(i = 0;i < y;i++)
    {
        output *= x;
    }
    return output;
}

int main()
{
    int T, i;
    scanf("%d",&T);
    for(i = 0;i < T;i++)
    {
        int n = -1;
        double output = 0;
        char input[52];
        scanf("%s",input);
        char*pt = input + 1;
        while(*pt)
        {
            output += (*(pt++) - '0')*pow(8,n);
            n--;
            //printf("%d",*pt - '0');
        }
        printf("case #%d:\n%lf\n",i,output);
    }
    return 0;
}