#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int cmp(const void*a,const void*b)
{
    return *((int *)a)-*((int *)b);
}
int gcd(int a,int b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
int main()
{
    int n,s;
    scanf("%d%d",&n,&s);
    int a[1001]={0};
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    a[n]=1000002;
    qsort(a,n,sizeof(a[0]),cmp);
   //  for(int i=0;i<=n;i++)
   //     printf("%d ",a[i]);

int i=0;
for(i<n)
{
    int j;
    for(j=i;j<=n;j++)
        if(a[j]>a[i])break;
    int tmp=(j-i)*(a[j]-a[i]);
    if(s>tmp){s-=tmp;i=j;}
    else{int g=gcd(tmp*(a[j]-a[i]),s);
    
    
    }
    
}



}
