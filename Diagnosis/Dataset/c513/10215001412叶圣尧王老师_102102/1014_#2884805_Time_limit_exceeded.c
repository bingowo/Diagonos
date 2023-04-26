#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    int A,B;int i,j=0,k=0,num,digit;int a[20],b[20];
    scanf("%d %d",&A,&B);digit=A%B;
    while(A)
    {
        a[k++]=A%3;
        A/=3;B/=3;
        if(B>0)j++;
    }a[k]=0;
    for(i=0;i<=k;i++)
    {
        a[i]+=1;
        if(a[i]>2){a[i]-=3;a[i+1]+=1;}
    }if(a[k]>0)k++;
    for(i=k-1;i>=0;i--)
    {
        if(a[i]==0)b[k-i-1]=2;
        else b[k-i-1]=a[i]-1;
    }
    int t=0;
    while(b[t]==0&&t<k-j-1)t++;
    for(i=t;i<k-j;i++)printf("%d",b[i]);
    for(t=k;t>=k-j||b[t]!=0;t--)k--;
    if(digit!=0&&t!=k-j-1)printf(".");
    for(i=k-j;i<k;i++)printf("%d",b[i]);
}