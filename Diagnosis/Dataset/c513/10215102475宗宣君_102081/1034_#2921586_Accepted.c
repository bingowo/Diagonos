#include <stdio.h>
#include <string.h>
#include <stdlib.h>
double a[26];
int cmp(const void*c,const void*d)
{
    char A,B;
    int m,n;
    A = *(char *)c;B = *(char *)d;
    m = A;n = B;
    if(A>=92) m = m-32;
    if(B>=92) n = n-32;
    if(a[m-'A']<a[n-'A']) return 1;
    else if(a[m-'A']==a[n-'A']&&m==n&&A<B) return 1;
    else if(a[m-'A']==a[n-'A']&&m!=n&&m>n) return 1;
    else return -1;
}
int main()
{
    int T,i,j;
    scanf("%d",&T);
    for(i = 0;i<T;i++)
    {
       char s[110];
       for(j = 0;j<26;j++)
            scanf("%lf",&a[j]);
       scanf("%s",s);
       qsort(s,strlen(s),sizeof(char),cmp);
       printf("case #%d:\n",i);
       printf("%s\n",s);
    }
    return 0;
}
