#include <stdio.h>
#include <stdlib.h>
#define mod 210
#define max 1000000007
int sub(char t[150],int l,int r)
{
    int s=0,i=0;
    for(i=l;i<=r;i++)
    {
        s=s*10+t[i]-'0';
        s=s%mod;
    }
    return s;
}
void jisuan(int h)
{
    char s[150]={0};
    scanf("%s",s);
    int f[100][mod]={0};memset(f,0,sizeof(f[0][0])*21000);
    int i=0,j=0,t=0,k=0,sum=0;
    for(i=0;s[i];i++)
    {
        f[i][sub(s,0,i)]=f[i][sub(s,0,i)]+1;
        f[i][sub(s,0,i)]=f[i][sub(s,0,i)]%max;
        for(j=0;j<i;j++)
        {
            t=0;t=sub(s,j+1,i);
            for(k=0;k<mod;k++)
            {
                f[i][(k+t)%mod]=f[i][(k+t)%mod]+f[j][k];
                f[i][(k+t)%mod]=f[i][(k+t)%mod]%max;
                f[i][(k+mod-t)%mod]=f[i][(k+mod-t)%mod]+f[j][k];
                f[i][(k+mod-t)%mod]=f[i][(k+mod-t)%mod]%max;
            }
        }
    }
    for(i=0;i<mod;i++)
    {
        if(i%2==0 || i%3==0 || i%5==0 || i%7==0)
        {
            sum=(sum%max+f[strlen(s)-1][i]%max)%max;
        }
    }
  printf("%d\n",sum);
}
int main()
{
    int N,h;
    scanf("%d",&N);
    for(h=0;h<N;h++)jisuan(h);
}
