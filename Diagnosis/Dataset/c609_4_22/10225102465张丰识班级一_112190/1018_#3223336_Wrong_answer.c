#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp (const void*a,const void *b) {
  return *(int *)a>*(int *)b?1:-1;
}
int main()
{
    int n;
    scanf ("%d", &n);
    int s[100000];
    int a[50000];
    int p;
    int i=0;
    while ((scanf ("%d", &p))!=EOF) {
        s[i]=p;
        i++;
    }
    i=0;
    qsort (s,n,sizeof(s[0]),cmp);
    int cm=0;
    int m=0;
    m=n/2;
    int res=0;
    while (m>-1) {
       cm=s[i+1]-s[i];
       //printf ("%d\n", cmp);
       a[i]=cm;
       //printf ("%d\n", a[i]);
       i++;


       m--;
       //printf ("%d\n", a[i]);
    }
    qsort (a,n-1,sizeof(a[0]),cmp);
    for (int k=0;k<3;k++) {
        //printf ("%d\n", a[k]);
    }
    m=n/2;
    i=0;
    for (;i<m;i++) {
        res=res+a[i];
    }
    printf ("%d", res);

    return 0;
}
