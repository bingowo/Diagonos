#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp (const void*a,const void*b) {
  char *c=*(char **)a;
  char *d=*(char **)b;
  int sig=0;
  int si=0;
  int x=0;
  int y=0;
  int m=0;
  int n=0;
  int u=0;
  int v=0;
  for (;(*(c+m))!='\0';m++) {
    if ((47<*(c+m))&&(*(c+m)<58)) {
            u=1;

        sig++;

        x=x*10+(*(c+m))-'0';
        //printf ("%d\n", *(c+m));

    }
  }
  for (;(*(d+n))!='\0';n++) {
    if ((47<*(d+n))&&(*(d+n)<58)) {
            v=1;



        si++;

        y=y*10+(*(d+n))-'0';
        //printf ("%d\n", *(d+n));
    }
  }
  if (x!=y) {
    return x>y?1:-1;
  }

  else {
    if (x==y&&x>0) {
        return sig<si?1:-1;
    }
    if (u==0&&v==0) {
        return strcmp (c,d);
    }
    else if (si!=sig)
        return sig>si?1:-1;
    else return strcmp (c,d);
  }

}
int main()
{
    int i=0;
    char s[100];
    char b[100][100];
    char **a=&b[0][0];
    char *p;
    int len=0;
    while ((scanf("%s",s))!=EOF) {
         len=strlen(s);

        p=(char *)malloc(len+1);        //动态分配邮件地址存储空间

        strcpy(p,s);

        *(a+i)=p;


        i++;
    }
    //for (int k=0;k<i;k++) {
        //printf ("%s", a[k]);
    //}
    qsort (a,i,sizeof(a[0]),cmp);
    for (int k=0;k<i;k++) {
        printf ("%s", a[k]);
        printf (" ");
    }
    return 0;
}
