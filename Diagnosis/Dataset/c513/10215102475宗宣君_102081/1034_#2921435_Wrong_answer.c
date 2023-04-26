#include <stdio.h>
#include <string.h>
#include <stdlib.h>
double a[26];
int cmp(const void*c,const void*d)
{
    char A,B,m = 'A',n = 'A';
    A = *(char *)c;B = *(char *)d;
    if(A>=92) m = 'a';
    if(B>=92) n = 'a';
    if(a[A-m]<a[B-n]) return 1;
    else if(a[A-m]==a[B-n]&&A<B) return 1;
    else return -1;
}
int main()
{
    int T,i,j;
    scanf("%d",&T);
    for(i = 0;i<T;i++)
    {
       char s[101];
       for(j = 0;j<26;j++)
            scanf("%lf",&a[j]);
       scanf("%s",s);
       qsort(s,strlen(s),sizeof(char),cmp);
       printf("case #%d:\n",i);
       printf("%s\n",s);
       printf("%lf %lf",a[1],a[2]);
    }
    return 0;
}
