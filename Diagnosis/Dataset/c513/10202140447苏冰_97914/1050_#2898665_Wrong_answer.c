#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char x[100];
void R(char * s,char *x,int id,int len)
{
    int i = 0;
    for(i=0;i<len;i++)
    {
        x[i] = s[id+i];
    }
   x[i] = '\0';
}
int search1(char *s1,char *s2)
{
    int id = 0;
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    while(1)
    {
        R(s1,x,id,len2);
        if(strcmp(s2,x)==0)break;
        id++;
        if(id>=len1)return -1;
    }
    return id;
}
int search2(char *s1,char *s2)
{
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int id = len1-len2;
    while(1)
    {
        R(s1,x,id,len2);
        if(strcmp(s2,x)==0)break;
        id--;
        if(id<0)return -1;
    }
    return id;
}
int main()
{
    int T;
    scanf("%d",&T);
    char s1[85],s2[85],s[85];
    gets(s1);
    for(int cas=0;cas<T;cas++)
    {
        gets(s1);
        gets(s2);
        gets(s);
        int i,j,ans;
        i=search1(s,s1);
        j=search2(s,s2);
        if(i==-1 || j==-1) ans=0;
        else ans=j-i-strlen(s1);
        printf("case #%d:\n%d\n",cas,ans);
    }
    return 0;
}

