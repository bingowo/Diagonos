#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define N 40

int input(int(*p)[N])
{
    int i=0,n;
    char c;
    do
        scanf("%d%c",&p[i++][N-1],&c);
    while (c==',');
    return i;
}

int isprime(int a)
{
    int cnt=0;
    if (a==2) return 1;
    else if (a==1 || a%2==0) return 0;
    else
    {
        for (int i=1;i<=sqrt(a);i+=2)
        {
            if (a%i==0) cnt++;
        }
    }
    if (cnt>1) return 0;
    else return 1;
}

void mult_n(int a[],int n)
{
    int i;
    for (i=N-1;i>0;i--)
        a[i]*=n;
    for (i=N-1;i>0;i--)
    {
        a[i-1]+=a[i]/10;
        a[i]%=10;
    }
}

void add(int a[],int b[])
{
    int i;
    for (i=N-1;i>0;i--)
    {
        a[i]+=b[i];
        a[i-1]+=a[i]/10;
        a[i]%=10;
    }
}

void output(int a[])
{
    int i=0;
    while (i<N && a[i]==0) i++;
    if (i>=N)
    {
        printf("0\n"); return;
    }
    while (i<N)
        printf("%d",a[i++]);
    printf("\n");
}

int main()
{
    int p[25][N]={0};
    int d[N]={0};
    int arr[26]={2,3,5,7};
    int i=7,j=4;
    while (j<26)
    {
        i+=2;
        if (isprime(i)) arr[j++]=i;
    }
    int num=input(p);
    for (i=0;i<num;i++)
    {
        for (j=0;j<num-i-1;j++)
            mult_n(p[i],arr[j]);
        add(d,p[i]);
    }
    output(d);
    return 0;
}
