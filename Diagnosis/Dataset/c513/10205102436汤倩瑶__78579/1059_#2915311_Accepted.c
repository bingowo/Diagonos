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
int j=0;
while(s!=0)
{

    for(j=i;j<=n;j++)
        if(a[j]>a[i])break;

    int tmp=j*(a[j]-a[i]);

    if(s>tmp){s-=tmp;i=j;
   }
    else{
    int ans1=a[i]+s/j;
    int ans2=s%j;

   if(ans1!=0) printf("%d",ans1);
    if(ans2!=0){int g=gcd(ans2,j);if(ans1!=0)printf("+");printf("%d/%d",ans2/g,j/g);}
    s=0;

    }


    }

}



