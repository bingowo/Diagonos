#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char s[17],out[17];
int a[25]={0},k;

void dfs(int step)
{
    int i,p;
    if(a[k-1]==0)return;
    for(i=0;i<k;i++)
    {
        if(a[i]==1)
        {
            out[step]=s[i];
            if(out[step]<out[step-1])
                return;
            else
            {
                out[step+1]='\0';
                printf("%s\n",out);
                a[i]=0;
                dfs(step+1,k);
                a[i]=1;
            }
        }
    }
    return;
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
        memset(a,1,k);
        dfs(0);

    }
}