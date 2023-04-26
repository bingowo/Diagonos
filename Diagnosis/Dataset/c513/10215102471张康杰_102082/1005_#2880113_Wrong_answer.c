#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int T, i;
    scanf("%d",&T);
    for(i = 0;i < T;i++)
    {
        int n = 1;
        double output = 0;
        char input[52];
        scanf("%s",input);
        char*pt = input + 2;
        while(*pt)
        {
            output += (*pt - '0')*pow(0.125,n);
            pt++;//可能时pow函数出错
            n++;
            //printf("%d",*pt - '0');
        }
        printf("case #%d:\n%lf\n",i,output);
    }
    return 0;
}