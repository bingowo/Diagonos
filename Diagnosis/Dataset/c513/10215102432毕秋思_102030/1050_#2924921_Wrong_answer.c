#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int FindSubstrFromLeft(char*s,char*s1)
{
    char* p=strstr(s,s1);
    return p==0?-1:p-s;
}

int FindSubstrFromRight(char*s,char*s1)
{
    char*p=s,*p1=0;
    while ((p1=strstr(p,s1))!=0) p=p1+1;
    return p-s-1;
}

int max(int a,int b)
{
    return a>b?a:b;
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++)
    {
        char s1[81],s2[81],s[81];
        int maxDist=0,x,y;
        gets(s1);
        gets(s2);
        gets(s);
        x=FindSubstrFromLeft(s,s1);
        y=FindSubstrFromRight(s,s2);
        if(x!=-1&&y!=-1)
        {
            maxDist=max(maxDist,y-x-strlen(s1));
            x=FindSubstrFromLeft(s,s2);
            y=FindSubstrFromRight(s,s1);
            maxDist=max(maxDist,y-x-strlen(s2));
        }
        printf("case #%d:\n",t);
        printf("%d\n",maxDist);
    }
    return 0;
}
