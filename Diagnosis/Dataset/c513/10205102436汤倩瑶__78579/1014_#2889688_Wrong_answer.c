#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int gcd(int a,int b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
int main()
{
int a,b;
int bs=1,tt;
scanf("%d%d",&a,&b);
int g=gcd(a,b);
a=a/g;
b=b/g;

tt=b;
while(tt!=1){
    bs++;tt/=3;
}
int p[100]={0};
int t=a;
int cnt=0;
while(t!=0)
{
    p[cnt++]=t%3;
    t/=3;
}
int carry=0;
for(int i=0;i<cnt;i++)
{
    int k=p[i];
    p[i]=(1+k+carry)%3;
    carry=(1+k+carry)/3;
}
if(carry>0)p[cnt++]=carry+1;
for(int i=0;i<cnt;i++)
    p[i]=p[i]-1;
for(int i=0;i<cnt;i++)
{
    if(p[i]==-1)p[i]=2;
}

int flag=0;
for(int j=cnt-1;j>bs-1;j--)
    {printf("%d",p[j]);flag=1;}
if(flag==0)printf("0.");
else if(bs!=0)printf(".");
for(int j=bs-1;j>=0;j--)
    printf("%d",p[j]);




}
