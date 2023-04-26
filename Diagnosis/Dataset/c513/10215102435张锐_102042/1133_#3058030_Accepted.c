#include <stdio.h>
#include <stdlib.h>
int anti(int x)
{
    if(x==0) return 1;
    else return 0;
}
int main()
{
    int n;
    scanf("%d",&n);
    int s[50000]={0};s[0]=0;int p=1;
    for(int i=1;i<=n;i++)
    {
        int temp=p;
        for(int j=0;j<temp;j++)
        {
            s[p++]=anti(s[j]);
        }
    }
    for(int i=0;i<p;i++) printf("%d",s[i]);
    return 0;
}