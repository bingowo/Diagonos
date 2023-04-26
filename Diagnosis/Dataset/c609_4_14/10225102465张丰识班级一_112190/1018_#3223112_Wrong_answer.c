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
    int p;
    int i=0;
    while ((scanf ("%d", &p))!=EOF) {
        s[i]=p;
        i++;
    }
    i=0;
    qsort (s,n,sizeof(s[0]),cmp);
    int cmp=0;
    int m=0;
    m=n/2;
    int res=0;
    while (m) {
       cmp=s[i+1]-s[i];
       //printf ("%d\n", cmp);
       i++;
       res=res+cmp;
       cmp=0;
       m--;
       //printf ("%d\n", res);
    }
    printf ("%d", res);
    return 0;
}
