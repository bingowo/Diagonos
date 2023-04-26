#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int num[21]={0};

int ts(int a,int n,int y,int *num)
{
    int k;
    if(n==1){return a;num[1]=a;}
    else if(n==2){return 0;num[2]=a;}
    else if(n==3){return a;num[3]=a+a;}
    else if(n==4){return y;num[4]=num[3]+y;}
    else {k=ts(a,n-2,y)+ts(a,n-1,y);return k;num[n]=num[n-1]+k;}
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
    
    printf("%d",s[x]);
}