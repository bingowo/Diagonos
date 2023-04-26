#include<stdio.h>
#include<stdlib.h>
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
int gcd(int a,int b)
{
    int x=max(a,b),y=min(a,b);
    a=x;
    b=y;
    if(a%b==0)return b;
    else return gcd(b,a%b);
}
int cmp(const void *a,const void *b)
{
    int x=*(int*)a,y=*(int*)b;
    return x-y;
}
int main()
{
    int n,s;
    scanf("%d%d",&n,&s);
    int x[1000];
    for(int i=0;i<n;i++)
        scanf("%d",&x[i]);
    qsort(x,n,sizeof(x[0]),cmp);
    int cnt=1;
    for(int i=0;i<n;i++)
    {
        if(x[i]==x[i+1])cnt++;
        else break;
    }
    while(s>=cnt)
    {
        for(int i=0;i<cnt;i++)
            x[i]++;
        s-=cnt;
        cnt=1;
        for(int i=0;i<n;i++)
        {
            if(x[i]==x[i+1])cnt++;
            else break;
        }
    }
    if(s==0)printf("%d\n",x[0]);
    else if(x[0]==0)
        printf("%d/%d\n",s/gcd(s,cnt),cnt/gcd(s,cnt));
    else
        printf("%d+%d/%d\n",x[0],s/gcd(s,cnt),cnt/gcd(s,cnt));
    return 0;
}
