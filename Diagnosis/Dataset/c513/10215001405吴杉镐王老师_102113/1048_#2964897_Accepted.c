#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int T,n,l;
char s[2][1005];
int m[2][105],ans[405];
int solve(int l,int r,int c)
{
    if(l>r)
        return 1;
    if(l==r)
    {
        if(s[c][l]=='-')
            return -1;
        if(s[c][l]=='+')
            return 1;
    }
    int res=0,f=1;
    if(s[c][l]=='-')
    {
        f=-1;
        l++;
    }
    else if(s[c][l]=='+')
    {
        f=1;
        l++;
    }
    for(int i=l; i<=r; i++)
        res=res*10+s[c][i]-'0';
    return f*res;
}
int main()
{
    while(~scanf("%s%s",s[0],s[1]))
    {
        for(int i=0;i<105;i++)
            ans[i]=ans[i+105]=m[0][i]=m[1][i]=0;
        for(int c=0; c<2; c++)
            for(int i=0; s[c][i]; i++)
            {
                int j,k;
                for(j=i; s[c][j]; j++)
                    if(s[c][j]=='x')
                        break;
                for(k=j; s[c][k]; k++)
                    if(s[c][k]=='+'||s[c][k]=='-')
                        break;
                //printf("%d %d %d\n",i,j,k);
                if(s[c][j]!='x')
                    m[c][0]=solve(i,j-1,c);
                else
                {
                    int p=1;
                    if(s[c][j+1]=='^')
                        p=solve(j+2,k-1,c);
                    m[c][p]=solve(i,j-1,c);
                }
                i=k-1;
            }
        //for(int i=0; i<=10; i++) printf("%d %d\n",m[0][i],m[1][i]);
        for(int i=0;i<105;i++)
            for(int j=0;j<105;j++)
                ans[i+j]+=m[0][i]*m[1][j];
        for(int i=200;i>=0;i--)
            if(ans[i])
                printf("%d ",ans[i]);
        puts("");
    }
    return 0;
}