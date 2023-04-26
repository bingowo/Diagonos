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
    else return ts(a,n-2,y)+ts(a,n-1,y);
}
 
int main()
{
    int a,n,m,x;int y;
    scanf("%d %d %d %d",&a,&n,&m,&x);int s[n+1];
    for(y=1;;y++)
    {
        int sum=0;
        for(int i=1;i<=n-1;i++){sum+=ts(a,i,y);s[i]=sum;}
        s[n]=sum;
        if(sum==m)break;
    }
    
    printf("%d",a[1]);
}