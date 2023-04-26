#include <stdio.h>
#include <string.h>
typedef struct {char temp[100];} string;
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
void ans(string *s,int *answer)
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
    string s[2]={};
    while ((scanf("%s %s",s[0].temp,s[1].temp))==2)
    {
        int answer[100]={0};
        ans(s,answer);
        for (int k=0;k<50;k++)
        {
            if (answer[k]) 
                printf("%d ",answer[k]);
        }
        printf("\n");
    }
}