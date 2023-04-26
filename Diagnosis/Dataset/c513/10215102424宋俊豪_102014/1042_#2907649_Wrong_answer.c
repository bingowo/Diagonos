#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
char s[105],s1[105];
int t,l;
int cmp(const void *a,const void *b)
{
    char x=*(char*)a;
    char y=*(char*)b;
    return (int)x-(int)y;
}
char ans[105];
void slo(int dep,int las,int lim)
{
    if(las>=lim) return;
    for(int i=las+1;i<=lim;i++)
    {
        ans[dep+1]=s1[i];
        for(int j=1;j<=dep+1;j++) putchar(ans[j]);
        puts("");
        slo(dep+1,i,lim);
    }
}
int main()
{
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        scanf("%s",s+1);
        l=strlen(s+1);
        qsort(s+1,l,sizeof(char),cmp);
        int id=0,las=-1;
        for(int j=1;j<=l;j++)
        {
            if(s[i]!=las) s1[++id]=s[i];
            las=s[i];
        }
        printf("case #%d:\n",i);
        slo(0,0,id);
    }
    return 0;
}