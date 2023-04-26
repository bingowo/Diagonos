#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#define N 100

int cmp(const void *a, const void *b)
{
    char *s1,*s2;
    s1=(char *)a;
    s2=(char *)b;

    int sign1=1,sign2=1;
    if (*s1=='-') sign1=-1,s1++;
    else if (*s1=='+') s1++;
    if (*s2=='-') sign2=-1,s2++;
    else if (*s2=='+') s2++;

    if (sign1 != sign2) return sign1-sign2;

    char *p1,*p2;
    for (p1=s1;*p1&&*p1!='.';p1++);
    for (p2=s2;*p2&&*p2!='.';p2++);

    int len1=p1-s1;
    int len2=p2-s2;

    if (len1!=len2) return  sign1*(len1-len2);

    return sign1* strcmp(s1,s2);

}

int main()
{
    int n,i;
    char s[100][100];
    scanf("%d",&n);
    for ( i = 0; i < n; ++i) {
        scanf("%s",s);
    }
    qsort(s,n, sizeof(s[0]),cmp);
    for ( i = 0; i < n; ++i) {
        printf("%s\n",s);
    }
    return 0;
}