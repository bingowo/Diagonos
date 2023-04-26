#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    int T,i;
    scanf("%d",&T);
    getchar();
    for(i = 0;i < T;i++)
    {
        char line[101];
        gets(line);
        double stack[101] = {.0};
        int top = -1,len = strlen(line);
        for(int j = len - 1;j >= 0;j--)
        {
            double opr1,opr2;
            if(line[j] == ' ')
                continue;
            else if(!isdigit(line[j]))
                switch(line[j])
                {
                case '*':
                    opr1 = stack[top--];
                    opr2 = stack[top--];
                    stack[++top] = opr1 * opr2;
                    break;
                case '+':
                    opr1 = stack[top--];
                    opr2 = stack[top--];
                    stack[++top] = opr1 + opr2;
                    break;
                case '-':
                    opr1 = stack[top--];
                    opr2 = stack[top--];
                    stack[++top] = opr1 - opr2;
                    break;
                case '/':
                    opr1 = stack[top--];
                    opr2 = stack[top--];
                    stack[++top] = opr1 / opr2;
                    break;
                }
            else
            {
                int flag = j,cnt = 0;
                char temp[101];
                while(line[j] != ' ')
                    j--;
                for(int k = j + 1;k <= flag;k++)
                {
                    temp[cnt++] = line[k];
                }
                temp[cnt] = '\0';
                stack[++top] = atof(temp);
            }
        }
        printf("case #%d:\n%.6lf\n",i,stack[top]);
    }
    return 0;
}
