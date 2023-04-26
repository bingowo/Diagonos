#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int miao(char *s,int n)
{
    int len=strlen(s);int num=0;
    for(int i=0;i<len;i++)
    {
        if(s[i]=='9') return strlen(s);
        else num+=s[i]-'0';
    }
    num+=n;
    if(num%9==0) return strlen(s);
    else return 0;
}
int add1(char *s)
{
    int len=strlen(s);int next=1;
    if(miao(s))
        while(next==1)
        {
            if(len-1<0) s--;
            int temp=s[len-1]-'0'+next;
            if(temp>8) {next=1,s[len-1]=temp-9+'0';}
            else {next=0;s[len-1]=temp+'0';}
            len--;
            if(len-1<0) break;
        }
    else 
        while(next==1)
        {
            if(len-1<0) s--;
            int temp=s[len-1]-'0'+next;
            if(temp>9) {next=1,s[len-1]=temp-10+'0';}
            else {next=0;s[len-1]=temp+'0';}
            len--;
            if(len-1<0) break;
        }
    if(next==1) return 1;
    else return 0;
}
int main()
{
    char s[1000];int n=0;
    scanf("%s",s);
    int len=strlen(s);int bo=1;
    while(bo)
    {
        n=add1(s);
        int l=miao(s,n);
        if(l==0)
        {
            if(n!=0) printf("%d",n);
            for(int i=0;i<=strlen(s);i++) printf("%c",s[i]);
            break;
        }
    }
    return 0;
}