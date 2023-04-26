#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
    int A,B,sign;scanf("%d%d",&A,&B);
    if(A<0){sign=-1;A=A*-1;}
    else sign=1;
    int d1[100]=[0],d2[100]=[0],temp1=A/B,temp2=A%B,i,j;
    for(i=99;i>=0&&temp1!=0;i--)
    {
        d1[i]=temp1%3;
        temp1=temp1/3;
    }
    int k=0;
    for(i=99;i>=0&&temp2!=0;i--)
    {
        if(temp2!=0)k++;
        d2[i]=temp2%3;
        temp2=temp2/3;
    }
    int t=0;
    for(i=99;i>=0;i--)
    {
        d1[i]=d1[i]+1+t;
        t=d1[i]/3;
        d1[i]=d1[i]%3;
    }t=0;
    for(i=99;i>=0;i--)
    {
        d2[i]=d2[i]+1+t;
        t=d2[i]/3;
        d2[i]=d2[i]%3;
    }
    for(i=0;i<=99;i++)
    {
        d1[i]--;d2[i]--;
        if(d1[i]==-1)d1[i]=2;
        if(d2[i]==-1)d2[i]=2;
    }
    if(sign==-1)
    {
        if(d1[i]==2)d1[i]=1;
        else if(d1[i]==1)d1[i]=2;
        if(d2[i]==2)d2[i]=1;
        else if(d2[i]==1)d2[i]=2;
    }
    i=0;
    while(d1[i]==0)i++;
    if(i>=100)printf("0");
    for(;i<=99;i++)printf("%d",d1[i]);
    printf(".");
    j=99;
    while(d2[j]==0)j--;
    for(i=100-k;i<=j;i++)printf("%d",d2[i]);
}