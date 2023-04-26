#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char s[1000000];
char a[1000000];
char c[1000000][1000000];
char **q=&c[0][0];
int cmp (const void*a,const void*b) {
  int l1=strlen (*(char **)a);
  int l2=strlen (*(char **)b);
  return l1>l2?1:-1;
}
int main()
{
    scanf ("%s", s);
    int i=0;
    int k=0;
    int l=0;
    char *p;
    for (;i<strlen(s);i++) {
        while (s[i]==s[i+1]) {
         i++;
        }
        a[l]=s[i];
        for (int j=0;j<strlen(a);j++) {
            if (a[j]==s[i+1]) {
                    int len=strlen(a);
                    p=(char *)malloc(len+1);
                strcpy(p,a);
                *(q+k)=p;
                k++;
                free(p);
            }
        }
        l++;
    }
    qsort (q,strlen(q),sizeof(q[0]),cmp);
    printf ("%s", q[0]);
    return 0;
}
