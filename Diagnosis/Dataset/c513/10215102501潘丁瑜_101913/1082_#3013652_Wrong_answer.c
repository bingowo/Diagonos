#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define L 500

void input(int a[])
{
    char s[L+1]={0};
    scanf("%s",s);
    int i=0;
    while(s[i] != '.' && s[i])i++;
    int j,k;
    for(j=i-1,k=L;j>=0;j--,k--)
        a[k]=s[j]-'0';

    for(j=i+1,k=L+1;j<strlen(s);j++,k++)
        a[k]=s[j]-'0';
}

void add(int a[],int b[],int n)
{
    int i;
    for(i=2*L;i>0;i--)
        a[i] += b[i];
    carry(a,n);
}

void carry(int a[],int n)
{
    int i;
    if(a[L+n+1]>=5) a[L+n]++;
    for(i=2*L;i>0;i--)
    {
        a[i-1] += a[i]/10;
        a[i] %= 10;
    }


}

void output(int a[],int n)
{
    int i=0;
    while(i<=L && a[i]==0)i++;
    if(i>L) printf("0");
    else
    {
        while(i<=L) printf("%d",a[i++]);
    }
    printf(".");
    while(i<=L+n) printf("%d",a[i++]);

}
int main()
{
    int a[2*L+1]={0};
    int b[2*L+1]={0};
    input(a);
    input(b);
    int n;
    scanf("%d",&n);
    add(a,b,n);//a+=b;
    output(a,n);
    return 0;
}