#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int T,l,top1=0,top2=0;
char s[10005],stk1[10005],stk2[10005];

int main()
{
    scanf("%s",s+1);
    l=strlen(s+1);
    for(int i=1;i<=l;i++)
        if(s[i]>='a'&&s[i]<='z')
            s[i]=s[i]-'a'+'A';
    stk1[++top1]=s[1];
    for(int i=2;i<=l;i++)
    {
        if(s[i]>=stk1[top1])
            stk1[++top1]=s[i];
        else
            stk2[++top2]=s[i];
    }
    while(top1)
        putchar(stk1[top1--]);
    for(int i=1;i<=top2;i++)
        putchar(stk2[i]);
    return 0;
}