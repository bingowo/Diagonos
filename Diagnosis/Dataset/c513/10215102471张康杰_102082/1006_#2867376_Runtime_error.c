#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T,i,solution;
    scanf("%d",&T);
    char*input[T];
    int output[T];
    int table[46];
    table[0] = 0;
    table[1] = 1;
    table['-'] = -1;
    for(i = 0;i < T;i++)
    {
        scanf("%s",input[i]);
    }
    for(i = 0;i < T;i++)
    {
        char*pt = input[i];
        solution = table[*pt - '0']*3 +table[*(pt++) - '0'];
        while(*pt && *(pt + 1))
        {
            solution =  solution*3 + table[*(pt++) - '0'];
        }
        output[i] = solution;
    }
    for(i = 0;i < T;i++)
        printf("case #%d:\n%d\n",i,output[i]);
    return 0;
}
