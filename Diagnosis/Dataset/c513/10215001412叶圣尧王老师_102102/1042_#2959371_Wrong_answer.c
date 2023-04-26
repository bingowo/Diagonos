#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char s[17],out[17];
int k;

void dfs(char *s,int len,int i)
{
    if(i==k)return;
    for(;i!=k;i++)
    {
        out[len]=s[i];
        out[len+1]='\0';
        printf("%s",out);
        dfs(s,len+1,i+1);
    }
}

int main()
{
    int T,i,j;scanf("%d",&T);char c;
    for(int t=0;t<T;t++)
    {
        printf("case #%d:\n",t);
        scanf("%s",s);int a1[55]={0};
        for(i=0;i<strlen(s);i++)
        {
            if(s[i]>='A'&&s[i]<='Z')a1[s[i]-65]=1;
            else a1[s[i]-71]=1;
        }
        k=0;
        for(i=0;i<26;i++)if(a1[i]>0)s[k++]='A'+i;
        for(i=26;i<52;i++)if(a1[i]>0)s[k++]='a'+i-26;
        s[k]='\0';
        dfs(s,0,0);

    }
}