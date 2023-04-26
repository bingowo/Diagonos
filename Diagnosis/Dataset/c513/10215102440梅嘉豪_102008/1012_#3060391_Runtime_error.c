#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void input();
long long a=0,b=0;
char s[1000]={0};
void main()
{
    long long ta,tb;
    int r;
    input();
    // if((a==0)&&(b==0))
    // {
    //     printf("0");return;
    // }
    // printf("0");
    while((a!=0)||(b!=0))
    {
        if((a+b)%2) r=1;
        else r=0;
        s[strlen(s)]=r+'0';
        ta=(b-a+r)/2;
        tb=(-a-b+r)/2;
        a=ta;b=tb;
    }
    for(int i=strlen(s)-1;i>=0;i--) printf("%c",s[i]);
}
void input()
{
    char t[1000]={0},s[1000]={0},u[1000]={0};
    scanf("%s",s);
    int pa=0,pb=0;
    while(1)
    {
        if((s[pb]=='+')||(s[pb]=='-'))
        {
            if(pb==0)
            {
                pb++;continue;
            }
            else
            {
                for(int i=0;i<pb;i++)   t[strlen(t)]=s[i];
                a=atoll(t);
                pa=pb;pb++;
            }

        }
        else if(s[pb]=='i')
        {
            if(pb==0)   
            {
                b=1;return;
            }
            else if(s[pb-1]=='-')
            {
                b=-1;return;
            }
            else if(s[pb-1]=='+')
            {
                b=1;return;
            }
            else 
            {
                for(int i=pa;i<pb;i++)   u[strlen(u)]=s[i];
                b=atoll(u);
                return;
            }
        }
        else if(s[pb]==0)
        {
            for(int i=0;i<pb;i++)   t[strlen(t)]=s[i];
            a=atoll(t);return;
        }
        else    pb++;
    }
}
