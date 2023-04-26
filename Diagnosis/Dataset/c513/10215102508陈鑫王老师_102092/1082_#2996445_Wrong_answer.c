#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define L 502
void read(char s[],int a[])
{
    int i,len=strlen(s);
    for(i=0;i<len&&s[i]!='.';i++);
    for(int j=i-1,k=1;j>=0;j--,k++)
    {
        a[L-k]=s[j]-'0';
    }
    for(int j=i+1,k=0;j<len;j++,k++)
    {
        a[L+k]=s[j]-'0';
    }
}
void multi(int a1[],int a2[],int n)
{
    for(int i=1004;i>=L+n;i--)
    {
        int x=a1[i]+a2[i];
        if(x>9)
        {
            a1[i]=x%10;
            a1[i-1]+=x/10;
        }
        else a1[i]=x;
    }
    if(a1[L+n]>=5) a1[L+n-1]+=1;
    for(int i=L+n-1;i>=0;i--)
    {
        int x=a1[i]+a2[i];
        if(x>9)
        {
            a1[i]=x%10;
            a1[i-1]+=x/10;
        }
        else a1[i]=x;
    }
}
int main()
{
    int i,N,a1[1004]={0},a2[1004]={0};
    char s1[1004],s2[1004];
    scanf("%s %s %d",s1,s2,&N);
    read(s1,a1);
    read(s2,a2);
    multi(a1,a2,N);
    for(i=0;i<L&&a1[i]==0;i++);
    if(i==L)printf("0.");
    else
    {
        for(;i<L;i++)
        {
            printf("%d",a1[i]);
        }
        printf(".");
    }
    for(;i<L+N;i++)
    {
        printf("%d",a1[i]);
    }
    return 0;
}
