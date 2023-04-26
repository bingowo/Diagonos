#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp1 (const void*a,const void*b) {

    return *(int *)a>*(int *)b?1:-1;


}
int cmp2 (const void*a,const void*b) {
  return *(int *)b>*(int *)a?1:-1;
}
int main () {
 char p;
 scanf ("%c", &p);
int x;
 int s[100];
 int a[100];

 int i=0;
 while ((scanf ("%d", &x))!=EOF) {
    s[i]=x;
    i++;
 }
//printf ("%d", i);
 int j=0;

 int l=0;
 for (;j<i-1;j++) {
        //printf ("%d\n", s[j]);
   for (int k=j+1;k<i;k++) {

        if(s[j]==s[k]) {
            s[k]=0;
        }

    }

 }
 int y=0;
for (int x=0;x<i;x++) {

    if (s[x]) {
        a[y]=s[x];
         y++;
    }
    //printf ("%d\n", a[y]);

}

 if (p=='A') {
 qsort (a,y,sizeof(a[0]),cmp1);
 }
 else if (p=='D') {
   qsort (a,y,sizeof(a[0]),cmp2);
 }
 for (int m=0;m<y;m++) {
    printf ("%d ", a[m]);

 }
 return 0;

}
