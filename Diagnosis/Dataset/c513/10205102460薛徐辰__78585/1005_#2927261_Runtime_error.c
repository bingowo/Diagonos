#include<stdio.h>

int sub8(int* s,int now)
{
    int a=s[0]/8,b=s[0]%8;
    int i=0;
    while(i<=now||b!=0)
    {
        s[i++]=a;
        s[i]=b*10+s[i];
        b=s[i]%8;a=s[i]/8;
    }
    if(a!=0){s[i]=a;i++;}
    return i;
}

void solve(int k,char* s,int len)
{
    int l=len-1,ans[1000],now=1;
    for(;s[l]!='.';l--)
    {
        now=sub8(ans,now);
    }
    printf("case #%d:\n0.",k);
    for(int i=0;i<now;i++)printf("%d",ans[i]);
    printf("\n");
}

int main()
{
    int n;char s[50];
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int j=0;
        while(1){scanf("%c",&s[j]);if(s[j]=='\n')break;j++;}
        solve(i,s,j);
        
    }
    return 0;
}

