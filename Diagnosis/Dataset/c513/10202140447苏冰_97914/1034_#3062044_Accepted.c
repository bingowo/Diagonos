#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
int table[150];
double x[30];
int cmp(const void*_a,const void*_b)
{
    char* a=(char*)_a;
    char* b=(char*)_b;
    char ch1=*a,ch2=*b;
    if(*a>='a' && *a<='z') ch1=*a-32;
    if(*b>='a' && *b<='z') ch2=*b-32;
    if(x[ch1-'A']!=x[ch2-'A'])
    {
        return x[ch1-'A']>x[ch2-'A']?-1:1;
    }
    else
    {
        return table[*a]-table[*b];
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    char a[60]="aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxXyYzZ";
    for(int i=0;i<strlen(a);i++) table[a[i]]=i;
    for(int cas=0;cas<T;cas++)
    {
        for(int i=0;i<26;i++)
        {
            scanf("%lf",&x[i]);
        }
        char s[100];
        scanf("%s",s);
        qsort(s,strlen(s),sizeof(s[0]),cmp);
        printf("case #%d:\n",cas);
        printf("%s\n",s);
    }
    return 0;
}
