#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void readernumber(char*s,int*a)
{
    int i,k=0;
    for(i=strlen(s)-1;i>=0;i--)
    {
        if(s[i]!=',')a[k]=a[k]*10+s[i]-'0';
        else k++;
    }
}

void add(int a[],int b[],int c[])
{
    int prime[26]={97,91,89,83,79,73,71,67,61,59,53,47,43,41,37,31,29,23,19,17,13,11,7,5,3,2};
    int i,j,digit=0,sign;
    for(i=0;i<26;i++)
    {
        c[i]=a[i]+b[i]+digit;
        digit=c[i]/prime[25-i];
        c[i]=c[i]%prime[25-i];
        
    }
    sign=25;
   while(c[sign--]==0);
   for(j=sign+1;j>0;j--)printf("%d,",c[j]);
    printf("%d\n",c[j]);
}

int main()
{
    char s[100];int i,T;
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        int a[26]={0},b[26]={0},c[26]={0};
        scanf("%s",s);
        readernumber(s,a);
        scanf("%s",s);
        readernumber(s,b);
        printf("case #%d:\n",i);
        add(a,b,c);
    }
}

