#include<stdio.h>
int func(int n,int p,int m,int t)
{
    if(m==0){
        if(p==t)return 1;
        else return 0;
    }
    else{
        if(t==1)return func(n,p,m-1,2);
        else if(t==n)reurn func(n,p,m-1,n-1);
        else return func(n,p,m-1,t-1)+func(n,p,m+1,t+1);
    }
}
int main()
{
    int cas;
    scanf("%d",&cas);
    for(int i=0;i<cas;i++)
    {
        int n,p,m,t;
        scanf("%d",&n,&p,&m,&t);
        printf("%d\n",func(n,p,m,t));
    }
    return 0;
}