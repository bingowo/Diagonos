#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp(const void*a,const void*b) {
  int cnt=0;
  int c=*(int *)a;
  int d=*(int *)b;
  int co_c=c;
  int co_d=d;
  while (c) {
    cnt++;
    c=c/10;
  }
  int cn=0;
  while (d) {
    cn++;
    d=d/10;
  }
  if (cn!=cnt) {
    return cnt<cn?1:-1;
  }
  else {
    return co_c>co_d?1:-1;
  }
}
int s[1000000];
int main()
{

    int p;
    int i=0;
    while ((scanf ("%d", &p))!=EOF) {
        s[i]=p;
        i++;
    }
    qsort (s,i,sizeof(s[0]),cmp);
    for (int k=0;k<i;k++) {
        printf ("%d ", s[k]);
    }

    return 0;
}
