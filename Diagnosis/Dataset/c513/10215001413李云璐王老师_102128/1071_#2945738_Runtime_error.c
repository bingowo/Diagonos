#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

int c(int k,int n)
{
    int data1=1,data2=1;
    for(int p=0;p<n;p++)
    {data1*=k;data2*=n;
    k--;n--;}
    return data1/data2;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int a,b,k,n,m,ans;
        scanf("%d%d%d%d%d",&a,&b,&k,&n,&m);
        ans=c(k,n)*pow(a,n)*pow(b,m);
        printf("case #%d:\n",i);
        printf("%d\n",ans);
        
    }
    return 0;
}