#include <stdio.h>
#include <stdlib.h>
#include <string.h>
long long int weight(int i)
{
    long long int sum=1;
    int table[]={1,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
    for(int n=0;n<=i;n++)
    {
        sum=sum*table[n];
    }
    return sum;
}

int main()
{
    char s[100];
    long long int a=0;
    scanf("%s",s);
    int len=strlen(s);
    for(int i=len-1;i>=0;i-=2)
    {
       a=a+(s[i]-'0')*weight((len-1-i)/2);
    }
    printf("%lld",a);
    return 0;
}
