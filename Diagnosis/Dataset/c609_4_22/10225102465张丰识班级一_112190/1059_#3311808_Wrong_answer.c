#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#define ll long long

#define LEN 1006
#define N 100
typedef struct {
 char p[100];
} point;
int cmp(const void*a,const void*b) {
  char *s1,*s2;
  point s3,s4;
  s3=*(point *)a;
  s4=*(point *)b;
  s1=s3.p;
  s2=s4.p;
  int sign1=1;
  int sign2=1;
  if(*s1=='-')  {sign1=-1;
  s1++;
  }
  else if (*s1=='+') s1++;
  if (*s2=='-') {
    sign2=-1;
    s2++;
  }
  else if (*s2=='+') s2++;
  if (sign1!=sign2) return sign1-sign2;
  char *p1,*p2;
  for (p1=s1;*p1&&*p1!='.';p1++);
  for (p2=s2;*p2&&*p2!='.';p2++);
  int len1=p1-s1,len2=p2-s2;
  if (len1!=len2) return sign1*(len1-len2);
  return sign1*strcmp(s1,s2);
}
int main () {
 int n;
 point a[100];
 scanf ("%d", &n);
 for (int i=0;i<n;i++) {
    scanf("%s", a[i].p);
    qsort(a,n,sizeof(a[0]),cmp);
 }
 for (int j=0;j<n;j++) {
    printf ("%s\n",a[j].p);
 }
 return 0;
}
