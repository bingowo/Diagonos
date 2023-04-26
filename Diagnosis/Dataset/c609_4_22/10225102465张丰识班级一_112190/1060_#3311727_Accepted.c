#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 100
char *insert (char *s,int pos) {
  int i;
  for (int i=strlen(s)+1;i>pos;i--) s[i]=s[i-1];
  return s;
}
int main () {
 char s[2*N+1],t[2*N+1];
 int i=0;
 int len=0;
 scanf ("%s", s);
 for (len=strlen(s);i<len;i++) {
    if  (strcmp(insert(strcpy(t,s),i),s)<0) {
        len++;
        i++;
        strcpy(s,t);
        //printf ("%s\n", s);
        //printf ("%d\n", i);
    }

 }
 printf ("%s", s);
 return 0;
}
