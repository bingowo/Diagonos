#include<stdio.h>#include<stdlib.h>int main(){    int number;    scanf("%d",&number);    for(int i=0;i<number;i++)    {        int n;        scanf("%d",&n);        int a[n][51];        for(int j=0;j<n;j++)        {            int k=0;            while(scanf("%d",&a[j][k]&&a[j][k]!=-1))            {                k++;            }        }        qsort(a,n,sizeof(a[0]),cmp);        for(int t=0;t<n;t++)        {            int q=0;            for(q=0;a[t][q+1]!=-1;q++)            {                printf("%d",a[t][q]);            }            printf("%d\n",a[t][q]);        }    }    return 0;}