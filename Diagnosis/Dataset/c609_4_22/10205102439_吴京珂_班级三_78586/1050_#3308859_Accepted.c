#include <stdio.h>
#include <stdlib.h>
#define L 500

void input(int a[])
{
    char s[L+1];
    scanf("%s",s);
    int i=0,j,k;
    while(s[i] && s[i]!='.') i++;//定位小数点
    for(j=i-1,k=L; j>=0; j--,k--)
        a[k] = s[j]-'0';//整数部分
    for(j=i+1,k=L+1; j<strlen(s); j++,k++)
        a[k] = s[j]-'0';//小数部分
}

void add(int a[],int b[],int N)
{
    int i;
    for(i=2*L; i>L+N; i--)
    {
        a[i] += b[i];
        a[i-1] += a[i]/10;
        a[i] %= 10;
    }
    if(a[i+1] >= 5) a[i]++;
    for(i=L+N; i>0; i--)
    {
        a[i] += b[i];
        a[i-1] += a[i]/10;
        a[i] %= 10;
    }
}

void output(int a[],int N)
{
    int i=0;
    while(i<=L && a[i]==0) i++;//跳过前置0
    if(i>L) printf("0"); //整数部分为0
    else
    {
        while(i<=L) printf("%d",a[i++]);//整数部分
    }
    printf(".");
    while(i<=L+N) printf("%d",a[i++]);//小数部分
    printf("\n");
}

int main()
{
    int A[2*L+1]= {0},B[2*L+1]= {0},N;
    input(A);
    input(B);
    scanf("%d",&N);
    add(A,B,N); //A+=B
    output(A,N);
    return 0;
}



