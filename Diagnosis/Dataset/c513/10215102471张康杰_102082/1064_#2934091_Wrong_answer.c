#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
double polan(char(*a)[11])
{
    if(isdigit((*a)[0]))
        return atof(*a);
    else
    {
        if((*a)[0] == '+')
            return polan(a+1) + polan(a+2);
        else if((*a)[0] == '-')
            return polan(a+1) - polan(a+2);
        else if((*a)[0] == '+')
            return polan(a+1) / polan(a+2);
        else if((*a)[0] == '*')
            return polan(a+2) * polan(a+1); 
    }
}
int main()
{
    int T,i;
    scanf("%d",&T);
    for(i = 0;i < T;i++)
    {
        char input[100][11];
        int count = 0;
        //字符串输入时数据类型
        while(scanf("%s",input[count++]) && getchar() != '\n');
        printf("case #%d:\n%.6lf\n",i,polan(input));
        
    }
}