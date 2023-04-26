#include<stdio.h>
#include<stdlib.h>
int dfs(char S[], int index)
{
    int res = 0;
    while (index < strlen(S))
    {
        if (S[index] == '(')
        {
            //遇到左括号，则递归处理这一对括号，比如“((()))”,当index = 1，先处理里面的“(())”
            res += dfs(S, ++index);
        }
        else
        {
            //遇到了右括号，则说明有一対括号处理完毕
            ++index;
            if (res == 0)
            {
                //这是一対空括号比如“(())”，index = 2
                return 1;
            }
            else
            {
                //否则(A)这种，得成上2，比如"(())"，index = 3，res = 1
                return res * 2;
            }
        }
    }
    //形如“AB”这种形式，最后需要另外放回结果
    return res;
}

int scoreOfParentheses(char S[]) 
    {
        if (strlen(S) == 0)
        {
            return 0;
        }
        int index = 0;//已经处理到达的下标
        return dfs(S, index);
    }
    
int main()
{
    char S[51];
    scanf("%s",S);
    printf("%d",scoreOfParentheses(S));
    return 0;
}
    