#include<stdio.h>
#include<string.h>
#define N 61
int min(char s[])
{
    int i=0,j,digit=0,n=1,sum, t[128];
    for(i=0;i<128;i++)t[i]=-1;
    s[0]=1;i++;
  while(s[i])
    {
       if(t[s[i]]==-1)
       {t[s[i]]=digit;
       if(digit==0)digit=2;
       else digit+=1;
       n++;}
       i++;
    }
    if(n<2)n=2;
    for(j=0,sum=0;j<strlen(s);j++)
    {
        sum=sum*n+t[s[j]];
    }
    return sum;
}

int main()
{
    int n,i;char s[N];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {scanf("%s",s);
    printf("case #%d:\n%d",i,min(s));}
    return 0;

}