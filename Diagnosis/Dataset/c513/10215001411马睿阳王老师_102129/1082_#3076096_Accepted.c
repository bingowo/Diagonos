#include<stdio.h>
#include<string.h>
#define L 500

void input(int a[])//输入和存储
{
    char s[2*L+1];
    scanf("%s",s);
    int i=0,j,k,l;
    while(s[i]&&s[i]!='.') i++;
    for(j=i-1,k=L;j>=0;j--,k--)
        a[k]=s[j]-'0';
    for(j=i+1,k=L+1;j<strlen(s);j++,k++)
        a[k]=s[j]-'0';

}

void add(int a[],int b[],int N)//加法计算
{
    int i,k,j;
    for(j=2*L;j>L+N;j--)
    {
        a[j]+=b[j];
        if(a[j]>=10)
        {
            a[j-1]+=a[j]/10;
            a[j]%=10;
        }
    }
    if(a[L+N+1]>=5) a[L+N]++;
    for(j=L+N;j>0;j--)
    {
        a[j]+=b[j];
        if(a[j]>=10)
        {
            a[j-1]+=a[j]/10;
            a[j]%=10;
        }
    }
}

void output(int a[],int N)
{
    int i=0,k;
    while(a[i]==0&&i<=L) i++;
    if(i>L) printf("0");
    else
    {
        for(k=i;k<=L;k++)
        printf("%d",a[k]);
    }
    printf(".");
    for(k=L+1;k<=L+N;k++)
        printf("%d",a[k]);
}

int main()
{
    int a[2*L+1]={0},b[2*L+1]={0},n;
    input(a);
    input(b);
    scanf("%d",&n);
    add(a,b,n);
    output(a,n);
    return 0;
}
