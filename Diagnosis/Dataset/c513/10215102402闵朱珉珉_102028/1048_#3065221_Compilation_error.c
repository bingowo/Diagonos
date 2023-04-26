#include <stdio.h>
#include <string.h>
typedef struct {char temp[100];} string;
int answer[100]={0};
void change (char *s,int *a)
{
    int i=0,flag=1,t=0,pow=0;
    while (s[i])
    {
        if (s[i]=='-')
        {
            flag=-1;
            i++;
        }
        else if(s[i]=='+')
        {
            i++;
        }
        while (s[i]>='0'&&s[i]<='9')
        {
            t=t*10+s[i]-'0';
            i++;
        }
        if (s[i]=='\0')
        {
            a[0]=t*flag;
            return;
        }
        else if(s[i]=='x')
        {
            if (t==0) t=1;
            i++;
            if (s[i]=='^')
            {
                while (s[i]>='0'&&s[i]<='9')
                {
                    pow=pow*10+s[i]-'0';
                    i++;
                }
            }
            else pow=1;
            a[pow]=t*flag;
            t=0;pow=0;flag=1;
        }
    }
}
int anslen(string *s)
{
    int a[50]={0},b[50]={0};
    change (s[0].temp,a);
    change (s[1].temp,b);
    for (int i=0;i<50;i++)
    {
        for (int j=0;j<50;j++)
            answer[i+j]+=a[i]*b[j];
    }
    
    
}
int main()
{
    char c;
    string s[2]={};
    int i=0,j=0;
    while (c=getchar()!=EOF)
    {
        if (c==' ')
        {
            s[i].temp[j]='\0';
            i++;
        }
        else if (c=='\n')
        {
            s[i].temp[j]='\0';
            i=0;j=0;
            for (int k=0;k<50;k++)
            {
                if (answe[i]) 
                    printf("%d%c",answer[k],k==len-1?'\n':' ');
            }
        }
        else
        {
            s[i].temp[j]=c;
            j++;
        }
    }
}