#include<stdio.h>
#include<string.h>
#define N 10005

int main()
{
    char s[N];
    char c;int p=0;
    while((c=getchar())!=EOF)s[p++]=c;
    s[p]=0;
    printf("%s",s);
    return 0;
}
