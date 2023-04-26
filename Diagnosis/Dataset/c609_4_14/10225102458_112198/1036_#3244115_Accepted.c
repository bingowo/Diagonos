#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int p(int a)
{
    int m=1;
    for(int i=0;i<a;i++){
        m*=2;
    }
    return m;
}
int main()
{
    char s[52];
    int max=0;
    scanf("%s",s);
    int len=strlen(s);
    int cnt=0;
    for(int i=0;i<len;i++){
        if(s[i]=='('){cnt++;}
        else
        if(s[i]==')'){cnt--;if(s[i-1]=='(')max+=p(cnt);}
    }
    printf("%d",max);
    return 0;
}
