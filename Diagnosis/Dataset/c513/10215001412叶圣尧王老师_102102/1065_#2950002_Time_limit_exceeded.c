#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int num[21]={0};

int ts(int a,int n,int y)
{
    if(n==1)return a;
    else if(n==2)return 0;
    else if(n==3)return a;
    else if(n==4)return y;
    if(num[n]>0)return num[n];
    else {num[n]=ts(a,n-2,y)+ts(a,n-1,y);return num[n];}
}
 
int main()
{
    int a,n,m,x;int y;
    scanf("%d %d %d %d",&a,&n,&m,&x);
    for(y=1;;y++)
    {
        int sum=0;
        for(int i=1;i<=n-1;i++)sum+=ts(a,i,y);
        if(sum==m)break;
        for(int i=1;i<n;i++)num[i]=0;
    }
    int sum=0;
    for(int i=1;i<=x;i++)sum+=ts(a,i,y);
    printf("%d",sum);
}