#include<stdio.h>
#include<string.h>
#include<string.h>
#include<math.h>

int haozi(int n,int p,int m,int t)
{
    int data,cha=p-t;
    if(p>=n+1||p<=0) return data=0;
    if(abs(cha)==m) return data=1;
    if(abs(cha)>m) return data=0;
    else return haozi(n,p-1,m-1,t)+haozi(n,p+1,m-1,t);
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int n,p,m,t,data,duo;
        scanf("%d%d%d%d",&n,&p,&m,&t);
        if((m-abs(p-t))%2!=0||abs(p-t)>m) data=0;
        else data=haozi(n,p,m,t);
        printf("%d\n",data);
    }
    return 0;
}