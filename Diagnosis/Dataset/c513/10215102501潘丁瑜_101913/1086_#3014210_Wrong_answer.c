#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define L 500

void Input(int a[])
{
    char s[2*L+1]={0};
    scanf("%s",s);
    int i=0;
    while(s[i] != '.' && s[i]) i++;
    int j,k;
    for(j=i-1,k=L;j>=0;j--,k--)
        a[k] = s[j]-'0';

    for(j=i+1,k=L+1;j<strlen(s);j++,k++)
        a[k] = s[j]-'0';

}

int compare(int a[],int b[])
{
    int i=0;
    for(i=0;i<=2*L;i++)
    {
        if(a[i] > b[i]) return 1;
        else if (a[i] < b[i]) return -1;
    }
    if(i > 2*L) return 0;
}
void minus(int a[],int b[])
{
    int i=0;
    for(i=0;i<=2*L;i++)
        a[i] -= b[i];
}

void round(int a[],int n)
{
    int i=0;
    if(a[L+n+1] >= 5) a[L+n]++;
    for(i=L+n+1;i<=2*L;i++)
        a[i]=0;
    carry(a);
}
void borrow(int a[])
{
    int i;
    for(i=2*L;i>=0;i--)
    {
        if(a[i] < 0)
        {
            a[i] += 10;
            a[i-1] --;
        }
    }
}

void carry(int a[])
{
    int i;
    for(i=2*L;i>=0;i--)
    {
        if(a[i] > 9)
        {
            a[i] %= 10;
            a[i-1] += a[i]/10;
        }
    }
}
void output(int a[],int n,int flag)
{
    int i=0;
    while(i<=L && a[i]==0 ) i++;
    if(flag == -1) printf("-");
    if(i>L) printf("0");
    else
        while(i<=L)printf("%d",a[i++]);
    printf(".");
    while(i<=L+n)printf("%d",a[i++]);
}

int main()
{
    int a[2*L+1]={0};
    int b[2*L+1]={0};
    Input(a);
    Input(b);
    int flag;
    flag = compare(a,b);

    //四舍五入
    int n;
    scanf("%d",&n);

    if(flag == 1)
    {
        minus(a,b);
        borrow(a);
        round(a,n);
        output(a,n,flag);
    }
    else
    {
        minus(b,a);
        borrow(b);
        round(b,n);
        output(b,n,flag);
    }
    return 0;
}