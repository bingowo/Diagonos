#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int T, i;
    scanf("%d",&T);
    for(i = 0;i < T;i++)
    {
        int n；
        double output = 0;
        char input[52];
        scanf("%s",input);
        for(n = 0;n < strlen(input);n++)
        {
            output += (*pt - '0')*pow(0.125,n+1);//可能时pow函数出错
            //printf("%d",*pt - '0');
        }
        int accuracy = 3*n;
        printf("case #%d:\n%.*lf\n",i,accuracy,output);
    }
    return 0;
}
//
