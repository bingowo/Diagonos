#include <stdio.h>
#include <stdlib.h>
int num[102]={0};
int f(int n,int k)
{
    if(n<=2)
        return num[n];
    else if(num[n]!=0)
        return num[n];
    else
    {
        for(int i=n-1;i>=n-k-1;i=i-1)
            if(i>0)
                num[n]=num[n]+num[i];
        return num[n];
    }
}
int main()
{
    num[0]=0;
    num[1]=0;
    num[2]=1;
    int k,n;
    scanf("%d %d",&k,&n);
    printf("%d",f(n,k));
    return 0;
}
