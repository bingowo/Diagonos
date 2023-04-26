#include<stdio.h>
int main()
{
    int a=1,i=0,b;
    char c,s[31];
    int flag=1,j=0,x=0;
    int s1=0,s2=0;
    while(scanf("%c",&c)!=EOF)
    {
        s[i]=c;
        i++;
        if(c=='.') flag=0;
        if(flag==1) a=a*3;
        else j++;
    }
    a=a/3;
    while(s[x++]!='.'&&x<i)
    {
        if(s[x-1]=='1') s1=s1+a,a=a/3;
        else if(s[x-1]=='2') s1=s1-a,a=a/3;
    }
    a=1;
    while(j--) a=a*3;
    b=a;
    a=a/3;
    for(;x<i;x++)
    {
        if(s[x]=='1') s2+=a;
        else if(s[x]=='2') s2-=a;
        a=a/3;
    }
    printf("%d %d %d",s1,s2,b);
    return 0;
}