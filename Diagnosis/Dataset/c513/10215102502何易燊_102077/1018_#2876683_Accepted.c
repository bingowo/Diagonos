#include <stdio.h>
#include <string.h>
#define N 1000

int table[30] = {1,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103};

void copy(int a[],int b[])
{
    for (int i=0;i<N;i++) a[i] = b[i];
}

void prime(int a[],int i)
{
    int p = 0;
    do
    {
        a[p++] = table[i]%10;
        table[i] /= 10;
    } while (table[i]>0);
    
}

void mul(int a[],int b[],int c[])
{
    for (int i=0;i<N/2;i++)
        for (int j=0;j<N/2;j++) c[i+j] += a[i]*b[j];
    for (int i=0;i<N;i++)
    {
        c[i+1] += c[i]/10;
        c[i] %= 10;
    }
}

void plus(int a[],int b[])
{
    for (int i=0;i<N/2;i++)
    {
        a[i] += b[i];
        a[i+1] += a[i]/10;
        a[i] %= 10;
    }
}

main()
{
    char s[1000];
    scanf("%s",s);
    if (s[0]=='0'&&s[1]==0) {printf("0");return 0;}
    int num[N][N]; int p=0,t=0;
    for (int i=strlen(s)-1;i>=0;i--)
    {
        if (s[i]==',') {p++; t=0;continue;}
        num[p][t++] = s[i]-'0';
    }

    int value[N]={}, a[N]={}, b[N]={}, c[N]={1};
    
    int ans[N] = {};
    for (int i=0;i<=p;i++)
    {
        prime(b,i);
        mul(b,c,a);
        mul(a,num[i],value);
        plus(ans,value);
        copy(c,a);
        memset(b,0,sizeof(b));
        memset(a,0,sizeof(a));
        memset(value,0,sizeof(value));
    }
    int pin;
    for (pin=N-1;pin>=0;pin--) if (ans[pin]!=0) break;
    for (int i=pin;i>=0;i--) printf("%d",ans[i]);
    printf("\n");
    return 0;
}