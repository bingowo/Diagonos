#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int miao(char *s)
{
    int len=strlen(s);int num=0;
    for(int i=0;i<len;i++)
    {
        if(s[i]=='9') return strlen(s);
        else num+=s[i]-'0';
    }
    if(num%9==0) return strlen(s);
    else return 0;
}
void add1(char *s)
{
    int len=strlen(s);int next=1;
    while(next==1)
    {
        if(len-1<0) s--;
        int temp=s[len-1]-'0'+next;
        if(temp>9) {next=1,s[len-1]=temp-10+'0';}
        else {next=0;s[len-1]=temp+'0';}
        len--;
    }
}
int main()
{
    char s[20000];
    scanf("%s",s);
    int len=strlen(s);
    while(1)
    {
        add1(s);
        int l=miao(s);
        if(l==0)
        {
            for(int i=0;i<=strlen(s);i++) printf("%c",s[i]);
            break;
        }
    }
    return 0;
}
