
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int T,l1,l2;
int max(int a,int b)
{
    if(a>b) return a;
    return b;
}
int solve(char *s1,char *s2)
{
    int cnt=0,l=strlen(s1+1);
    s1[0]=0;
    for(int i=1;i<=l;i++)
        if(s1[i]!=s1[i-1]&&s1[i]!=s1[i+1])
            s2[++cnt]=s1[i];
    int f=0;
    for(int i=1;i<=cnt;i++)
    {
        if(s2[i]==s2[i-1])
            f=1;
        s1[i]=s2[i];
    }
    s1[cnt+1]=0;
    return f;
}
char s[105],s1[105],s2[105];
int main()
{
    scanf("%d",&T);
    for(int c=0;c<T;c++)
    {
        scanf("%s",s+1);
        l1=strlen(s+1);
        //printf("%d %d\n",l1,l2);
        int ans=0;
        for(int i=1;i<=l1;i++)
        {
            for(int j=1;j<=i;j++)
                s1[j]=s[j];
            s1[i+1]=s[i];
            for(int j=i+1;j<=l1;j++)
                s1[j+1]=s[j];
            s1[l1+2]=0;
            while(solve(s1,s2));
            //printf("!!! %s\n",s1+1);
            ans=max(ans,l1-strlen(s1+1)+1);
        }
        printf("case #%d:\n%d\n",c,ans);
    }
    return 0;
}