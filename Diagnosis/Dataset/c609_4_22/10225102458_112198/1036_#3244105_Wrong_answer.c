#include <stdio.h>
#include <stdlib.h>
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
    int i=0,cnt=0;
    while(s[i]!='\0'){
        while(s[i++]=='(')cnt++;
        max+=p(cnt-1);
        while(s[i++]==')')cnt--;
    }
    printf("%d",max);
    return 0;
}
