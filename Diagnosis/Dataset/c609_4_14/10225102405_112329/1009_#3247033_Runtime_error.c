#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 120
int ones(unsigned char d)
{
    int r;
    for(r=0;d>0;d>>=1) if(d&&1) r++;
    return r;
}

int huajian(int a,int b)
{
    return a%b?huajian(a%b,b):b;
}

void solve()
{
    int k=0,count=0,cout=0,G;
    char s[N+2];
    fgets(s,sizeof s,stdin);
    for(k=0;s[k]!='\n';k++)
    {
        count+=ones(s[k]);
        cout+=8;
    }
    G=huajian(count,cout);
    printf("%d/%d",count/G,cout/G);
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        solve();
    }
}
