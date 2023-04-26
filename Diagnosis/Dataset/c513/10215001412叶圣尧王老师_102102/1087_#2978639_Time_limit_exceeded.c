#include<stdio.h> 
#include<stdlib.h>
#include<string.h>
#include<math.h>
int flag=-1;
int cmp(char s[])
{
    int i;
    for(i=0;i<strlen(s)-1;i++)
        if(s[i]==s[i+1]){return -1;break;}
    if(i=strlen(s)-1)return 0;
}

void  add(char s[])
{
    int i,d;
    for(i=0;i<strlen(s);i++)
    {
        d=s[i]-'0'+1;
        s[i]=d%10+'0';
        if(d/10==0)break;
    }
    if(i==strlen(s)&&d==1)s[i]='1';
}

void val(char s[])
{
    int len=strlen(s);
    do
    {
        add(s);
    }while(cmp(s));
}

int main()
{
    int T;scanf("%d",&T);char s[101]={'\0'},out[101]={'\0'};
    for(int t=0;t<T;t++)
    {
        printf("case #%d:\n",t);
        scanf("%s",s);
        for(int i=strlen(s)-1;i>=0;i--)
            out[i]=s[strlen(s)-1-i];
        val(out);
        for(int i=strlen(out)-1;i>=0;i--)
            printf("%c",out[i]);
        printf("\n");
    }
}