#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#define L 500

void Input(int a[])
{
    char s[L+1];
    scanf("%s",s);
    int j,k,i=0;
    while(s[i]&&s[i]!='.') i++;
    for(j=i-1,k=L;j>=0;j--,k--)
    {
        a[k]=s[j]-'0';
    }
    for(j=i+1,k=L+1;j<strlen(s);j++,k++)
    {
        a[k]=s[j]-'0';
    }
}

void Add(int a[],int b[],int n)
{
    int i;
    for(i=2*L;i>L+n;i--)
    {
        a[i]+=b[i];
        a[i-1]+=a[i]/10;
        a[i]%=10;
    }
    if(a[i+1]>=5) a[i]++;
    for(i=L+n;i>0;i--)
    {
        a[i]+=b[i];
        a[i-1]+=a[i]/10;
        a[i]%=10;
    }
}

void Output(int a[],int n)
{
    int i=0;
    while(i<=L&&a[i]==0) i++;
    if(i>L) printf("%d",0);
    else
    {
        while(i<=L) printf("%d",a[i++]);
    }
    printf("%c",'.');
    while(i<=L+n) printf("%d",a[i++]);
    printf("\n");
}

int main()
{
    int A[2*L+1]={0};
    int B[2*L+1]={0};
    int N;
    Input(A);
    Input(B);
    scanf("%d",&N);
    Add(A,B,N);
    Output(A,N);
    return 0;
}
