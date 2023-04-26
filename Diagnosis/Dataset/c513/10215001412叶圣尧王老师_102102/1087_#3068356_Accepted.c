#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int add(char *s,int k)
{
    int i,j,temp,t=1;
    for(i=k;i>=0&&t!=0;i--)
    {
        temp=s[i]-'0'+t;
        s[i]=temp%10+'0';
        t=temp/10;
    }return i+1;
}

int main()
{
    int T;scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        printf("case #%d:\n",i);
        char s[102];scanf("%s",s+1);s[0]='0';
        int add(char*s,int k);
        add(s,strlen(s)-1);int j,m=strlen(s)-1;
        for(j=1;j<strlen(s)&&j<=m;j++)
        {
            if(s[j]==s[j-1])
            {
                add(s,j);m=j;j=1;
            }
        }
        for(j=m+1;j<strlen(s);j++)
        {
            if(s[j-1]=='0')s[j]='1';
            else s[j]='0';
        }
        if(s[0]=='0')printf("%s\n",s+1);
        else printf("%s\n",s);
    }
}
