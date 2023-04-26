#include<stdio.h>
#include<string.h>
#define N 61
long long int min(char s[])
{
    int i=0,j=0,digit=0,n=1,t[128];
    long long int sum=0;
    for(i=0;i<128;i++)t[i]=-1;
    t[s[0]]=1;j++;
  while(j<strlen(s))
    {
       if(t[s[j]]==-1)
       {t[s[j]]=digit;
       digit=(digit==0?2:digit+1);
       n++;}
       j++;
    }
    if(n<2)n=2;
   for(int k=0;k<strlen(s);k++)
    sum=sum*n+t[s[k]];
   return sum;
}

int main()
{
    int n,i;char s[N];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {scanf("%s",s);
    printf("case #%d:\n%lld\n",i,min(s));}
    return 0;

}
