#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
int cmp(const void*_a,const void*_b)
{
    char* a=(char*)_a;
    char* b=(char*)_b;
    char* p1=a;char* p2=b;
    int n1=0,n2=0;
    while(*p1 !='\0')
    {
        if(isdigit(*p1)) n1=n1*10+(*p1-'0');
        p1++;
    }
     while(*p2 !='\0')
    {
        if(isdigit(*p2)) n2=n2*10+(*p2-'0');
        p2++;
    }
    if(n1>n2) return 1;
    else if(n1<n2) return -1;
    else if(n1==n2) return strcmp(a,b);
}
int main()
{
    char s[110][35];
    int n=0;
    while(scanf("%s",s[n])!=EOF)
    {
        n++;
    }
    qsort(s,n,sizeof(s[0]),cmp);
    for(int i=0;i<n;i++)
    {
        printf("%s ",s[i]);
    }
    return 0;
}
