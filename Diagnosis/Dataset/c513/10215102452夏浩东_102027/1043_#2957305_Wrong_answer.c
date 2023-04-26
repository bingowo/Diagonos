#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int max(int a, int b, int c)
{
    if(a>=b && a>=c) return a;
    else if(b>=a && b>=c) return b;
    else return c;
}
int func(char*ss,int i,char c,int len)
{
    char s[102];
    for(int j=0;j<len;j++) s[j]=ss[j];
    if(i==0)
    {
        for(int j=len;j>=0;j--) s[j+1]=s[j];
        s[0]=c;
    }
    else if(i==len){s[i]=c;s[i+1]='\0';}
    else
    {
        for(int j=len;j>=i;j--) s[j+1]=s[j];
        s[i]=c;
    }
    while(1)
    {
        char ns[102]={'\0'};
        int k=0,repeat=0;
        if(s[0]!=s[1]){ns[0]=s[0];k++;}
        for(int j=1;j<(int)strlen(s)-1;j++)
        {
            if(s[j]!=s[j-1] && s[j]!=s[j+1]) ns[k++]=s[j];
            else repeat=1;
        }
        if(s[(int)strlen(s)-1]!=s[(int)strlen(s)-2]) ns[k]=s[(int)strlen(s)-1];
        strcpy(s,ns);
        if(strlen(s)==1) repeat=0;
        if(repeat==0) break;
    }
    return len+1-strlen(s);
}
int main()
{
    int cnt=0;
    scanf("%d",&cnt);
    for(int i=0;i<cnt;i++)
    {
        char s[102];
        scanf("%s",s);
        int len=(int)strlen(s);
        int temnum=0,maxnum=0;
        for(int i=0;i<len+1;i++)
        {
            temnum=max(func(s,i,'A',len),func(s,i,'B',len),func(s,i,'C',len));
            maxnum=temnum>maxnum?temnum:maxnum;
        }
        printf("case #%d:\n",i);
        printf("%d\n",maxnum);
    }
    return 0;
}