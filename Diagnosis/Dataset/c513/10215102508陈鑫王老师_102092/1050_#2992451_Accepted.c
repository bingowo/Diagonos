#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char* strrstr(char s[],char s1[])
{
    int lens=strlen(s);
    int lens1=strlen(s1);
    char *ps=s+lens-1,*ps1=s1+lens1-1;
    while(*ps)
    {
        while(*ps1&&*ps&&*ps==*ps1)
        {
            ps--;
            ps1--;

        }
        if(!*ps1) return ps+1 ;
        else if(*ps!=*ps1) ps1=s1+lens1-1;
        ps--;
    }
    if(!*ps) return NULL;

}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        int ret;
        char s1[81],s2[81],s[81];
        scanf("%s %s %s",s1,s2,s);
        if(strstr(s,s1)==NULL||strstr(s,s2)==NULL)
            ret=0;
        else
        {
            int ret1,ret2;
            char*p1,*p2,*p11,*p22;
            p1=strstr(s,s1);
            p2=strstr(s,s2);
            p11=strrstr(s,s1);
            p22=strrstr(s,s2);
            if(p1<p22)
            {
                p1+=strlen(s1);
                ret1=p22-p1;
            }
            else if(p1>p22)
            {
                p22+=strlen(s2);
                ret1=p1-p22;
            }
            else ret1=0;
            if(p2<p11)
            {
                p2+=strlen(s2);
                ret2=p11-p2;
            }
            else if(p2>p11)
            {
                p11+=strlen(s1);
                ret2=p2-p11;
            }
            else ret2=0;
            ret=ret1>ret2?ret1:ret2;
        }
        printf("case #%d:\n%d\n",i,ret);

    }
    return 0;
}
