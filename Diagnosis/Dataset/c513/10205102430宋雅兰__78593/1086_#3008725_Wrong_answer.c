#include<stdio.h>
#include<string.h>
#define L 500
void Input(int a[])
{
    char s[L+1];
    scanf("%s",s);
    int i=0,j,k;
    int l=strlen(s);
    while(s[i]&&s[i]!='.')i++;
    for(j=i-1,k=L;j>=0;j--,k--)
    a[k]=s[j]-'0';
    for(j=i+1,k=L+1;j<l;j++,k++)
    a[k]=s[j]-'0';
}
void minus(int a[],int b[],int n)
{
    int i;
    for(i=2*L;i>L+n;i--)
    {
        if(a[i]>b[i])a[i]-=b[i];
        else{
            a[i-1]--;
            a[i]=a[i]+10-b[i];
        }
    }
    if(a[i+1]>4)a[i]++;
    for(i=L+n;i>0;i--)
    {
        if(a[i]>b[i])a[i]-=b[i];
        else{
            a[i-1]--;
            a[i]=a[i]+10-b[i];
        }
    }
    if(a[i]<b[i])printf("-");
}
void Output(int a[],int n)
{
    int i=0;
    while(i<=L&&a[i]==0)i++;
    if(i>L)printf("0");
    else{
        while(i<=L)printf("%d",a[i++]);
    }
    printf(".");
    while(i<=L+n)printf("%d",a[i++]);
    printf("\n");
}
int main()
{
    int a[2*L+1]={0},b[2*L+1]={0},n;
    Input(a);
    Input(b);
    scanf("%d",&n);
    minus(a,b,n);
    Output(a,n);
    return 0;
}