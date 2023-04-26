#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int a[25],b[25];//a是以0结尾不含101的个数，b为1结尾
int main()
{   int n;
    a[3]=4;b[3]=3;
    a[4]=7;b[4]=5;
    for(int i=5;i<21;i++)
    {
        a[i]=a[i-1]+b[i-1];//末尾加0
        b[i]=b[i-1]+a[i-1]-b[i-2];//以一结尾，不包括10的不含101的个数
    }
    while(scanf("%d",&n))
    {
        if(n==-1)
            break;
        printf("%d\n",a[n]+b[n]);
    }
    return 0;
}

