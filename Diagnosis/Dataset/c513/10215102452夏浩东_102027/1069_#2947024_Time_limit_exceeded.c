#include <stdio.h>
#include <string.h>
char* FNum(char *L,int len)
{
    char NL[50];
    for(int i=len-1;i>=0;i--)
    {
        NL[len-i-1]=L[i];
    }
    char *p=NL;
    return p;
}
int judge(char *s,int len)
{
    int res=1;
    for(int i=0;i<len/2;i++) if(s[i]!=s[len-i-1]){res=0;break;}
    return res;
}
int main()
{
    char s1[50];
    char s2[50];
    scanf("%s",s1);
    int count=0;
    while(judge(s1,(int)strlen(s1))==0)
    {
        strcpy(s2,FNum(s1,(int)strlen(s1)));
        int left=0;
        for(int i=(int)strlen(s1)-1;i>=0;i--)
        {
            int num=s1[i]-'0'+s2[i]-'0'+left;
            s1[i]=(char)(num%10+'0');
            left=num/10;
        }
        if(left!=0)
        {
            for(int i=(int)strlen(s1);i>=0;i--) s1[i+1]=s1[i];
            s1[0]=(char)(left+'0');
        }
        count++;
    }
    printf("%d %s",count,s1);
    return 0;
}