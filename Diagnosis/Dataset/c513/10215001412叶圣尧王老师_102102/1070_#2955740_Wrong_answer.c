#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int a[21]={0};

int f(int n)
{
    if(n<3)return pow(2,n);
    else if(n==3)return pow(2,n)-1;
    else if(a[n]>0)return a[n];
    else 
    {
        a[n]=f(n-1)+f(n-2)-f(n-4); return a[n];
    }
}

int main()
{
    int n;
    while(scanf("%d",&n) &&n!=-1)
    {
        printf("%d\n",f(n));
    }
}