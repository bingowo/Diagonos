#include <stdio.h>
#include <stdlib.h>
void add(int *a,int *b)
{
    int last=0;
    for(int i=49;i>=0;i--)
    {
        int temp=a[i]+b[i]+last;
        if(temp>9) a[i]=temp-10,last=1;
        else a[i]=temp,last=0;
    }
}
int main()
{
    int s[100][50];
    memset(s,0,sizeof(0));
    s[0][49]=0;s[1][49]=1;
    int k,n;
    scanf("%d%d",&k,&n);
    if(k>2)
    {
        for(int i=2;i<k;i++)
        {
            for(int j=0;j<i;j++)
                add(s[i],s[j]);
        }
    }
    for(int i=k;i<n;i++)
    {
        for(int j=1;j<=k;j++) add(s[i],s[i-j]);
    }
    if(n==1) printf("1\n");
    else
    {
        int p;
        for(p=0;p<50;p++) if(s[n-1][p]!=0) break;
        for(;p<50;p++) printf("%d",s[n-1][p]);
    }
    return 0;
}
