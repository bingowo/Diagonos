#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX(a,b) ((a)>(b)?(a):(b))

int score(char *s)
{
    int len=strlen(s);
    int stack[len+1];
    int top=0;
    stack[top++]=0;
    for(int i=0;i<len;i++)
    {
        if(s[i]=='(') stack[top++]=0;
    else{
        int v=stack[--top];
        stack[top-1]+=MAX(2*v,1);
    }
    }
    return stack[top-1];
}
int main()
{
	char s[55];
	scanf("%s",s);
	int ss=score(s);
	printf("%d",ss);
	return 0;
}
