#include<stdio.h>
#include<string.h>
void Turn2(int x,int y)
{
    int i,j,n;
    char s[10000];
    for(i = 0;x>0;i++)
    {
        n = x%y;
        x = x/y;
        if(n<10) s[i] =n +'0';
        else s[i] = n+'A'-10;
    }
    for(j = i-1;j>=0;j--)
    {
        printf("%c",s[j]);
    }
}
int Turn1(char s[10000],int a)
{
    int y = 1;
    int n = strlen(s);
    int i,x = 0,u;
    for(i = n;i>0;i--)
    {
        if(s[i]>='A'&&s[i]<='F')u = s[i]-'A'+10;
        else if(s[i]>='a'&&s[i]<='f')u = s[i]-'a'+10;
        else u = s[i] -'0';
        x += u*y;
        y= a*y;
    }
    return x;
}
int main()
{
    int a,b,n;
    char s[10000];
    scanf("%d",&a);
    scanf("%s",s);
    scanf("%d",&b);
    n = Turn1(s[10000],a);
    Turn2(n,b);
    return 0;
}
