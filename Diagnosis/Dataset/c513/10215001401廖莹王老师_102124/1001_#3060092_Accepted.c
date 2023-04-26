#include <stdio.h>
#include <stdlib.h>
void fanzhuan(char s[100])
{
    int i=0,j=0;
    char c;
    j=strlen(s)-1;
    for(;i<j;i++,j--)
    {
        c=s[i];s[i]=s[j];s[j]=c;
    }
}
void jinzhi(int n,int r,char s[100])
{
    int i=0,k=0;
    if(n<0)n=n*(-1);
    for(i=0;n>0;i++)
    {
        k=n%r;
        if(k>=0 && k<=9)s[i]=k+'0';
        else if(k>=10)s[i]=k+55;
        n=n/r;
    }
    s[i]=0;
    fanzhuan(s);
}
void jisuan()
{
    int n,r;
    char s[100];
    scanf("%d %d",&n,&r);
    if(n==0)printf("0\n");
    jinzhi(n,r,s);
    if(n>0)printf("%s\n",s);
    else printf("-""%s\n",s);
}
int main()
{
    int N,h;
    scanf("%d",&N);
    for(h=0;h<N;h++)jisuan();
    return 0;
}
