#include<stdio.h>
#include<string.h>


    int scoreOfParentheses(char S[]) {
        int i, deep = 0, ans = 0;
        for(i = 0; i < strlen(S); ++i)
        {
        	if(S[i] == '(')
        		deep++;
        	else	//S[i]== ')'
        	{
        		--deep;
        		if(S[i-1] == '(')//连续的左右括号
        			ans += (1<<deep);
        	}
        }
        return ans;
    }
};
    
int main()
{
    char S[51];
    scanf("%s",S);
    printf("%d",scoreOfParentheses(S));
    return 0;
}
    