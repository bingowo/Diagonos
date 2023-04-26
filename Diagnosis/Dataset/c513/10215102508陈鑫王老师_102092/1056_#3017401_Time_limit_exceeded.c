#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct
{
    char s[15];
}dic;
int com(char *p,char*q,char*s)
{
    if(q-p+1!=strlen(s))return 0;
    else
    {
        char *l=p;
        for(int i=0;i<strlen(s);l++,i++)
        {
            if(s[i]!=*l)return 0;
        }
        return 1;
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    dic stand[n];
    for(int i=0;i<n;i++)
    {
        scanf("%s",stand[i].s);
    }
    char s[5001];
    scanf("%s",s);
    char *p=s,*q=s+strlen(s)-1;
    while(*p&&p<=q)
    {
        int flag=0;
        for(int i=0;i<n;i++)
        {
            if(com(p,q,stand[i].s))
            {
                printf("%s%c",stand[i].s,p==s+strlen(s)-1?'\n':' ');
                p=q+1;
                q=s+strlen(s)-1;
                flag=1;
                break;
            }

        }
        if(flag==0&&p==q)
        {
            printf("%c%c",*p,p==s+strlen(s)-1?'\n':' ');
            p=q+1;
            q=s+strlen(s)-1;

        }
        else if(flag==0)
        {
            q--;
        }

    }
    return 0;
}
