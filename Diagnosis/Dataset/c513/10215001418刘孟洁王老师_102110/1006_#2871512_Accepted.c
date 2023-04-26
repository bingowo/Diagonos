#include<stdio.h>
#include<string.h>
#define N 1000000
int main()
{
    int i,j,k,n;
    char s[N];
    long long int sum;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
       scanf("%s",s);
       for(j=0,sum=0;j<strlen(s);j++)
       {
            k=s[j]-'0';
            if(s[j]=='-')k=-1;
            sum=sum*3+k;
       }
       printf("case #%d:\n%lld\n",i,sum);
    }
    return 0;
}
