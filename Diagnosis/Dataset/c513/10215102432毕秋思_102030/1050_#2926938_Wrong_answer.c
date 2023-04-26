#include<stdio.h>
#include<string.h>

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

void solve()
{
    char s1[81]={0},s2[81]={0},s[81]={0};
    int maxDist,x,y;
    gets(s1);
    gets(s2);
    gets(s);
    x=FindSubstrFromLeft(s,s1);
    y=FindSubstrFromRight(s,s2);
    if(x==-1||y==-1) maxDist=0;
    else
    {
        maxDist=y-x-strlen(s1);
        x=FindSubstrFromLeft(s,s2);
        y=FindSubstrFromRight(s,s1);
        maxDist=maxDist>(y-x-strlen(s2))?maxDist:(y-x-strlen(s2));
    }
    printf("%d\n",maxDist);
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++)
    {
        printf("case #%d:\n",t);
        solve();
    }
    return 0;
}
