#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int T,i;
    scanf("%d",&T);
    //char*input[T]；
    //int output[T];
    int table[46];
    table[0] = 0;
    table[1] = 1;
    table['-'] = -1;
//    for(i = 0;i < T;i++)
//    {
//        scanf("%s",input[i]);//输入出错，输入一直卡在此处
//    }
    for(i = 0;i < T;i++)
    {
        long long int solution = 0;
        char input[1000];
        scanf("%s",input);
        int j;
        for(j = 0;j < strlen(input);j++)
        {
            solution = solution*3 + table[input[j]];
        }
        printf("case #%d:\n%lld\n",i,solution);
    }
    return 0;
}