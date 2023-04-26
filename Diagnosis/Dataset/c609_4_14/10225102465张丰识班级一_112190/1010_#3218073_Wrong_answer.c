#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
int main () {
 int m=-25000;
 int n=-16;
 int x=0;
 char p[100];
 for (int l=0;fabs(m)>0;l++) {
    x=m%n;
    //printf ("%d\n", x);
    if ((fabs(x))>9) {
        if (x<0)
        x=-x;
        //printf ("%d\n", x);
        x=x+'0';
        p[l]=x;
    printf ("%c\n",p[l]);
    }
    else {
        if (x<0)
        x=-x;
        //printf ("%d\n", x);
        x=x+'A'-10;
        p[l]=x;
        printf ("%c\n",p[l]);
   }
   m=m/n;
   //printf ("%c",p[l]);
 }
 printf ("%s", p);


 return 0;

}