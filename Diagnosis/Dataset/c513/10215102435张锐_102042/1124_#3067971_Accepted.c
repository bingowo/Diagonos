#include <stdio.h>
#include <stdlib.h>

int yue(int a,int b)//a>b   不能约return 0
{
    int bo=0;
    for(int i=2;i<=a;i++)
    {
        if(a%i==0&&b%i==0) {bo=1;break;}
    }
    return bo;
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int f=0;f<t;f++)
    {
        int n;scanf("%d",&n);
        int s[1000];int p=0;int c;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&c);int j;
            for(j=0;j<p;j++)
            {
                if(s[j]==c) break;
            }
            if(j==p) s[p++]=c;
        }
        printf("case #%d:\n",f);
        int num=0;
        for(int i=0;i<p;i++)
        {
            for(int j=0;j<p;j++)
            {
                if(s[i]<s[j])
                {
                    if(yue(s[i],s[j])==0) num++;
                }
            }
        }
        printf("%d\n",num);
    }
    return 0;
}