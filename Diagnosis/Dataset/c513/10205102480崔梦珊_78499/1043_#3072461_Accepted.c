#include<stdio.h>
#include<string.h>
int panduan(char* s)
{
    int l=strlen(s);
    for(int i=0;i<l-1;i++)
    {
        if(s[i]==s[i+1])
        {
            return 1;
        }
    }
    return 0;
}

void charu(char* s,char c,int a)
{
    char temp[200]={0};
    int l=strlen(s);
    for(int i=0;i<l+1;i++)
    {
        if(i<a) temp[i]=s[i];
        if(i==a) temp[i]=c;
        if(i>a) temp[i]=s[i-1];
    }
    strcpy(s,temp);
}

int f(char* s)
{
    char temp[200]={0};
    int l=strlen(s);
    int flag=0;
    for(int i=0;i<=l-1;i++)
    {
        if(s[i]!=s[i+1])
        {
            temp[flag]=s[i];
            flag++;
        }
        else
        {
            while(s[i]==s[i+1])
            {
                i++;
            }
        }
    }
    /*printf("temp:%s\n",temp);
    printf("panduan:%d\n",panduan(temp));
    printf("strlen:%d\n",strlen(temp));*/
    if(panduan(temp)==1) return f(temp);
    else return strlen(temp);
}

int main()
{
    int t;
    scanf("%d\n",&t);
    for(int i=0;i<t;i++)
    {
        char s[101]={0};
        scanf("%s",s);
        int len=strlen(s);
        int ans=0;
        for(int j=1;j<len;j++)
        {
            char sx[101]={0};
            char sy[101]={0};
            char sz[101]={0};
            strcpy(sx,s);
            strcpy(sy,s);
            strcpy(sz,s);
            charu(sx,'A',j);
            charu(sy,'B',j);
            charu(sz,'C',j);
            int a=len+1-f(sx);
            int b=len+1-f(sy);
            int c=len+1-f(sz);
            if(a>ans) ans=a;
            if(b>ans) ans=b;
            if(c>ans) ans=c;
            /*printf("%d %d %d\n",a,b,c);*/
        }
        printf("case #%d:\n%d\n",i,ans);
    }
}
