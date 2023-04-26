#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int cmp (const void*a,const void*b);
char t[26];
int main () {

  int i=0;
  char b[100][100];
    char **a=&b[0][0];
    char *p;
    int len=0;
    char s[100];
    while ((scanf ("%s", t))!=EOF) {
    while ((scanf ("%s", s))!=EOF) {

     len=strlen(s);

        p=(char *)malloc(len+1);        //动态分配邮件地址存储空间
        //for (int k=0;k<len;k++) {
            //s[k]=toupper(s[k]);
        //}
        strcpy(p,s);

        *(a+i)=p;


        i++;
    }
    qsort (a,strlen(a),sizeof(a[0]),cmp);
    int j=0;
    for (;j<i;j++) {
        printf ("%s ", *(a+j));
    }
    }

    return 0;
  }
  int cmp (const void*a,const void*b) {
  int *c=*(char **)a;
  int *d=*(char **)b;
  int u=0;
  int v=0;
  int q=0;
  int w=0;
  int cn=0;
  int cm=0;
  while (c[u]!='\0'||d[u]!='\0') {
        if(c[u]!=d[u]) {
    for (;q<strlen(t);q++) {
        if(toupper(c[u])==t[q]) {
            cn=q;
            //printf ("%d\n", cn);
        }
    }
    for (;w<strlen(t);w++) {
        if(toupper(d[u])==t[w]) {
            cm=w;
            //printf ("%d\n", cm);
        }
    }
    break;
        }
        u++;
  }
  return cn>cm?1:-1;

}
