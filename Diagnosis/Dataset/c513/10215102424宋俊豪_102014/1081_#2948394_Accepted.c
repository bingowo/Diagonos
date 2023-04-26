#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
int f(int b[],int n,int a)
{
    int t,i,id,carry;
    for(i=1; i<n; i++)
    {
        id=0;
        carry=0;
        while(b[id]!=-1)
        {
            t=b[id]*a+carry;
            b[id]=(t)%10;
            carry=(t)/10;
            id++;
        }
        while(carry>0)
        {
            b[id++]=carry%10;
            carry=carry/10;
        }
    }
    return id-1;
}
int main()
{
    int t,a,n,b[100];
    scanf("%d",&t);
    for(int i=0; i<t; i++)
    {
        for(int j=0; j<100; j++)
            b[j]=-1;
        scanf("%d%d",&a,&n);
        printf("case #%d:\n",i);
        if(n==0)
        {
            printf("1");
        }
        else
        {
            b[0]=a;
            int l=f(b,n,a);
            for(int j=l; j>=0; j--)
            printf("%d",b[j]);
        }
        printf("\n");
    }
}
