#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
char s[105],s1[105];
int T,l;

int cmp(const void* a,const void* b)
{
    char x=*(char *)a,y=*(char *)b;
    return 
        (int)x-(int)y;
}

char ans[105];

void dfs(int dep,int las,int lim)
{
    if(las>=lim) 
        return;
    for(int i=las+1;i<=lim;i++)
    {
        ans[dep+1]=s1[i];
        for(int j=1;j<=dep+1;j++) 
            putchar(ans[j]);
        puts("");
        dfs(dep+1,i,lim);
    }
}

int main()
{
    scanf("%d",&T);
    for(int c=0;c<T;c++)
    {
        scanf("%s",s+1);
        l=strlen(s+1);
        qsort(s+1,l,sizeof(char),cmp);
        int id=0,las=-1;
        for(int i=1;i<=l;i++)
        {
            if(s[i]!=las)
                s1[++id]=s[i];
            las=s[i];
        }
        printf("case #%d:\n",c);
        dfs(0,0,id);
    }
    return 0;
}
