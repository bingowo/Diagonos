#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ADD(int a[],int b[],int c[])
{
    int prime[26]={97,91,89,83,79,73,71,67,61,59,53,47,43,41,37,31,29,23,19,17,13,11,7,5,3,2};
    for(int i=25;i>=0;i--)
    {
        c[i]=c[i]+(a[i]+b[i])%prime[i];
        c[i+1]=(a[i]+b[i])/prime[i];
    }
}

void output(int a[])
{
    int k=-1;
    for(int i=0;a[i]==0;i++)k++;
    for(;k<26;k++)printf("%d,",a[k]);
}

char Readnumber(char s[],int a[])
{
    int k=25;
    for(int i=strlen(s);i>=0;i--)
    {
        if(isdigit(s[i]))a[k--]=s[i]-'0';
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        char s[100];
        int a[26]={0},b[26]={0},c[26]={0};
        scanf("%s",s);
        Readnumber(s,a);
        scanf("%s",s);
        Readnumber(s,b);
        ADD(a,b,c);
        printf("case #%d:\n",i);
        output(c);
    }
    return 0;
}