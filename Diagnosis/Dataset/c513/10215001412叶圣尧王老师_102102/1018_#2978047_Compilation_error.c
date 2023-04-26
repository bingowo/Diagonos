#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int prime[26]={97,91,89,83,79,73,71,67,61,59,53,47,43,41,37,31,29,23,19,17,13,11,7,5,3,2};

void add(int*a,int*b)
{
    int i,carry;
    for(i=0;i<100;i++)
    {
        int t=a[i]+b[i]+carry;
        a[i]=t%10;
        carry=t/10;
    }
}

int *mul(int*c,int a)
{
    int i=0,carry=0,len=0;int result1[100],result2[100];
    int a1=a%10,a2=a/10;
    for(i=0;c[i]==0;i++)
    {
        result1[i]=c[i];
        result2[i]=c[i];
    }
    for(;c[i]!=0;i++)
    {
        result1[i]=c[i];
        result2[i]=c[i];
    }
    len=i;
    for(i=0;i<len;i++)
    {
        int t=result1[i]*a1+carry;
        result1[i]=t%10;
        carry=t/10;
    }
    if(carry>0)result1[len]=carry;
    if(a2>0)
    {
        carry=0;
        for(i=0;i<len;i++)
        {
            int t=result2[i]*a2+carry;
            result2[i]=t%10;
            carry=t/10;
        }
        if(carry>0)result2[len]=carry;
        add(result1,result2);
    }
    return result1;
}

int main()
{
    int a[26],c[100]={0},d[100]={0},k=0,i;char s[100];
    scanf("%s",s);int lenth=strlen(s);
    for(i=0;i<lenth;i++)
    {
        if(s[i]==',')k++;
        else 
            a[k]=a[k]*10+s[i]-'0';
    }
    c[0]=[1];
    for(i=k;i>=0;i--)
    {
        c=mul(c,prime[25-k+i]);
        add(d,mul(c,a[i]));
    }
    for(i=100;d[i]==0;i--);
    for(;i>=0;i--)printf("%d",d[i]);
}