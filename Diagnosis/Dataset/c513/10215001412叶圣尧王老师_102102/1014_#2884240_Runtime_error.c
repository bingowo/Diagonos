#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    int A,B;int i,j,k=0,num,digit;int a[100],b[100];
    scanf("%d %d",A,B);
    num=A/B;
    digit=abs(A%B);
    if(digit>B/2&&num<0){num--;digit=digit-B;}
    else if(digit>B/2&&num>0){num++;digit-B;}
    for(;num!=0;)
    {
        a[k++]=num%3;
        num/=3;
    }a[k]=0;
    for(i=0;i<k;i++)
    {
        a[i]+=1;
        if(a[i]>2){a[i]-=3;a[i+1]+1;}
    }
    if(a[k]==1){a[k]+=1;k++;}
    for(i=k-1;i>=0;i--)
    {
        a[i]=a[i]-1;
        if(a[i]=-1)a[i]=2;
        printf("%d",a[i]);
    }
    
}