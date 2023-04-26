#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int score(char s[])
{
    int len= strlen(s);
    int start=0,res=0;
    for (int i = start; i < len; ++i) {
        start += s[i]=='('?1:-1;
        if (s[i]==')'&&s[i-1]=='('){
            res+=1<<start;
        }
    }
    return res;
}

int main()
{
    char s[51];
    int score;
    scanf("%s",s);
    int res=score(s);
    printf("%d",res);
    return 0;
}