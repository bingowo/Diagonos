#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 500
int compare(int a[],int b[])
{
    int ret=0;
    for(int i=0;i<2*N+1;i++ )
    {
        if(a[i]>b[i])
        {
            ret=1;break;
        }
    }
    return ret;
}
void ctof(char s[],int a[])
{
    int i,j,d,len=strlen(s);
    for(i=0;i<len&&s[i]!='.';i++);
    for(j=i-1,d=N;j>=0;j--,d--)
    {
        a[d]=s[j]-'0';
    }
    for(j=i+1,d=N+1;j<len;j++,d++)
    {
        a[d]=s[j]-'0';
    }
}
void minusf(int a[],int b[],int n)
{
    int i;
    for(i=2*N;i>N+n;i--)
    {
        if(a[i]>=b[i])a[i]-=b[i];
        else
        {
            a[i]=a[i]+10-b[i];
            a[i-1]-=1;
        }
    }
    if(a[i+1]>=5)a[i]+=1;
    for(;i>=0;i--)
    {
        if(a[i]>=b[i])a[i]-=b[i];
        else
        {
            a[i]=a[i]+10-b[i];
            a[i-1]-=1;
        }
    }
}
void print(int a[],int n)
{
    int i;
    for(i=0;i<=N&&a[i]==0;i++);
    if(i==N+1)printf("0");
    else
    {
        for(;i<=N;i++)
            printf("%d",a[i]);
    }
    printf(".");
    for(;i<=N+n;i++)
    {
        printf("%d",a[i]);
    }
    printf("\n");
}
int main()
{
    int n;
    int a[2*N+1]={0},b[2*N+1]={0};
    char s1[502],s2[502];
    scanf("%s %s %d",s1,s2,&n);
    ctof(s1,a);
    ctof(s2,b);
    if(compare(a,b))
    {
        minusf(a,b,n);
        print(a,n);
    }
    else
    {
        minusf(b,a,n);
        printf("-");
        print(b,n);
    }
    return 0;


}
