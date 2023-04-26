#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int judge(char*s)
{
    int len = strlen(s);
    int states[101] = {0};
    int top = 0;
    states[top] = 0;
    for(int i = 0; i<len; i++)
    {
        int state = states[top];
        char ch = s[i];
        switch(state)
        {
        case 0:
            if(ch == '(') states[++top] = 1;
            else if(ch == '[') states[++top] = 2;
            else if(ch == '{') states[++top] = 3;
            else return 0;
            break;
        case 1:
            if(ch == '{') states[++top] = 3;
            else if(ch == ')')
            {
                top--;
                if(states[top] != 0)
                    states[top] = 4;  //中括号中有小括号
            }
            else return 0;
            break;
        case 2:
        case 4:
            if(ch == '(') states[++top] = 1;
            else if(ch == ']')
            {
                if(state == 2) return 0;
                top--;
                if(states[top] != 0)
                {
                    states[top] = 5;  //大括号有中括号
                }
            }
            else return 0;
            break;
        case 3:
        case 5:
            if(ch == '[')
            {
                states[++top] = 2;
            }
            else if(ch == '}')
            {
                if(state == 3) return 0;
                top--;
            }
            else return 0;

            break;
        }
    }
    return states[top] == 0;

}

int main()
{
    int T = 0;
    scanf("%d", &T);
    while(T--)
    {
        char s[101] = {0};
        scanf("%s", s);
        printf(judge(s)?"Yes\n":"No\n");
    }
    return 0;
}
