#include <stdio.h>
#include <string.h>
char s[20][100000]={0};
void change(char *s)
{
    int len=strlen(s);
    for (int i=len;i<len*2;i++)
    {
        if (s[i-len]=='0')
            s[i]='1';
        else
            s[i]='0';
    }
}
void print(int n)
{
    if (n==0)
        s[0][0]='0';
    else
    {
        print(n-1);
        strcpy(s[n],s[n-1]);
        change(s[n]);
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    print(n);
    printf("%s",s[n]);
}
