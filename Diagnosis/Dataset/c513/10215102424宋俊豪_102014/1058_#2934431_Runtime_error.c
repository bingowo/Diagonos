#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
char s[2000],a[2000];
int main()
{
    int f=-1,f1=-1,id=0;
    while(gets(s)!=NULL)
    {
        int i=0;
        while(s[i])
        {
            if(f==1)
            {   i++;
                while(s[i]!='/'&&s[i-1]!='*'&&s[i])
                    i++;
                if(s[i]=='\0')
                    break;
                else
                {
                    f=-1;
                    i++;
                }
            }
            else
            {
                if(s[i]=='/'&&s[i+1]=='/')
                {
                    printf("\n");
                    break;
                }
                else if(s[i]=='/'&&s[i+1]=='*')
                {
                    f=1;i+=2;
                    while(s[i]!='/'&&s[i-1]!='*'&&s[i]!='\0')
                    {
                        i++;
                        printf("1");
                    }
                }
                else if(s[i]=='"')
                {
                    a[id++]=s[i];
                    i++;
                    while(s[i]!='"')
                    {
                        a[id++]=s[i];
                        i++;
                    }
                    a[id++]=s[i];
                }
                else
                {
                    a[id++]=s[i];
                    i++;
                }

            }
        }
        if(a[0]!='\0')
        {
            printf("%s\n",a);
            memset(a,0,2000);
        }
    }
}
