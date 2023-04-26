#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define N 100
int main()
{
    int A,B,sum=0,i=0,len=0;
    char s[N];
    scanf("%d",&A);
    scanf("%s",s);
    scanf("%d",&B);
    len=strlen(s);
    for(i=0;i<len;i++)
    {
        if(!isdigit(s[i]))
        s[i]=s[i]-'A'+10;
        sum=A*(sum+s[i]);
    }
    printf("%d",sum);
    return 0;
}

