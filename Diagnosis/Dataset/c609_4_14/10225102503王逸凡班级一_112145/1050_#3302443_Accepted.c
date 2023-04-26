#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define L 500

void Input(int a[]) //input a float number
{
    char s[L+1];
    scanf("%s",s);
    int i = 0,j,k;
    while (s[i] && s[i]!='.') //定位小数点
    {
        i++;
    }
    for(j = i-1,k=L;j>=0;j--,k--) //整数部分
    {
        a[k] = s[j] - '0';
    }
    for(j = i+1,k=L+1;j<strlen(s);j++,k++) //小数部分
    {
        a[k] = s[j] - '0';
    }
}

void add(int a[],int b[],int N)
{
    int i;
    for (i = 2*L;i>L+N;i--)
    {
        a[i] += b[i];
        a[i-1] += a[i]/10;
        a[i] %= 10;
    }
    if (a[i+1]>=5) a[i]++;
    for (i = L+N;i>0;i--)
    {
        a[i] += b[i];
        a[i-1] += a[i]/10;
        a[i] %= 10;
    }
}

void output(int a[],int N)
{
    int i = 0;
    for(i = 0;i<L;i++){
        if (a[i]!=0){
            break;
        }
    }
    for(i;i<=L;i++)
    {
        printf("%d",a[i]);

    }
    printf(".");
    for(i=L+1;i<=L+N;i++)
    {
        printf("%d",a[i]);
    }
}

int main()
{
    int A[2*L+1]={0},B[2*L+1]={0},N;
    Input(A);
    Input(B);
    scanf("%d",&N);
    add(A,B,N);
    output(A,N);
    return 0;
}
