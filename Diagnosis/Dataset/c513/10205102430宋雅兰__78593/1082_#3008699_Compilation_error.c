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
    for(j=i+1,k=L+1;j<=l;j++,k++)
    a[k]=s[j]-'0';
}
void add(int a[],int b[],int n)
{
    int i;
    for(i=2*L;i<L+n;i--)
    {
        a[i]+=b[i];
        a[i-1]+=a[i]/10;
        a[i]%=10;
    }
    if(a[i+1]>=5)a[i]++;
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
    add(a,b,n);
    Ouput(a,n);
    return 0;
}