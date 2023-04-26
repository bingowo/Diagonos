#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void solveint(int m) {
  int n=sizeof(m);
  char *p=&m;
  while (n>0) {
    printf ("%02x ", *p++);
    n--;
  }
  printf("\n");
}
void solvedouble(double t) {
  int q=sizeof(t);
  unsigned char *a=(unsigned char*)&t;
  while (q>0) {
    printf ("%02x ", *a++);
    q--;
  }
  printf ("\n");
}
int main()
{
    char s[100];
    while ((scanf("%s",s )!=EOF)) {
        if (strchr(s,'.')==0) {
            solveint(atoi(s));
        }
        else {
            solvedouble(atof(s));
        }
    }
    return 0;
}
