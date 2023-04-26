#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char n[],char m[])
{
    int i=0,j=strlen(n)-1;
    while(i<strlen(n))
    {
        m[i] = n[j];
        i++,j--;
    }
}
int main()
{
    char n[10001]={0};
    char m[10001]={0};
    scanf("%s",n);
    reverse(n,m);
    int count = 0;
    long long int s = 0;
    while(strcmp(n,m)!=0)
    {
        s = atoll(n)+atoll(m);
        count++;
        itoa(s,n,10);
        reverse(n,m);
    }
    printf("%d %lld",count,s);
    return 0;
}
