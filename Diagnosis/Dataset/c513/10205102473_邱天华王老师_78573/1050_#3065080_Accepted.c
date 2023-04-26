#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int findleft(char*s,char*s1)
{   
    char* p=strstr(s,s1);
    return p==0?-1:p-s;
}
int findright(char*s,char*s1)
{   
    char*p=s,*p1=0;
    while ((p1=strstr(p,s1))!=0) p=p1+1;
    return p-s-1;
}
int max(int a,int b) { return a>b?a:b; }

void solve(int i)
{   char s1[81],s2[81],s[81]; 
    getchar();
    int maxDist=0,x,y;
    scanf("%s%s%s",s1,s2,s);
    x=findleft(s,s1);
    y=findright(s,s2);
    if (x!=-1&&y!=-1) 
    {  
        maxDist=max(maxDist,y-x-strlen(s1));
        x=findleft(s,s2);
        y=findright(s,s1);
        maxDist=max(maxDist,y-x-strlen(s2));
    }
    printf("case #%d: \n",i);
    printf("%d\n",maxDist);
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        solve(i);
    }
    return 0;
}