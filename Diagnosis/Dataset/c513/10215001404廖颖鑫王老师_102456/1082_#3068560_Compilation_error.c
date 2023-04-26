
#define L#include <stdio.h>
#include <stdlib.h>
#include <string.h> 500
void Input(int a[])
{
    char s[L+1];
    scanf("%s",s);
    int i=0,j,k;
    while(s[i]&&s[i]!='.')//确定小数点的位置
    for(j=i-1,k=L;j>=0;j--,k--)
    {
        a[k]=s[j]-'0';
    }
    for(j=i+1,k=L+1;j<strlen(s);j++,k++)
    {
        a[k]=s[j]-'0';
    }
}

void Add(int a[],int b[],int N)
{
    int i;
    for(i=2*L;i>L+N;i--)
    {
        a[i]+=b[i];
        a[i-1]+=a[i]/10;
        a[i]%=10;
    }
    if(a[i+1]>=5)a[i]++;
    for(i=L+N;i>0;i--)
    {
        a[i]+=b[i];
        a[i-1]+=a[i]/10;
        a[i]%=10;
    }
}

void Output(int a[],int N)
{
    int i=0;
    while(i<L&&a[i]==0)i++;//跳过前置0
    if((i>L))printf("0");//整数部分为0
    else
        {
            while(i<=L)
            {printf("%d",a[i++]);}
        }
        printf('.');
        while(i<=L+N)
        {
            printf("%d",a[i++]);
        }
}

int main()
{
    int A[2*L+1]={0},B[2*L+1]={0};
    int N;
    scanf("%d",&N);
    Input(A),Input(B);
    Add(A,B,N);
    Output(A,N);
}
