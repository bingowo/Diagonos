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
        char*pt = input + 1;
        while(*pt)
        {
            output += *(pt++)*pow(0.125,n);
            n++;
        }
        printf("case #%d:\n%lf\n",i,output);
    }
    return 0;
}
