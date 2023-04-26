#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char s[10000]={0};
char a[10000]={0};
int main () {
  int A;
  scanf ("%d", &A);
  char n[50];
  scanf ("%s",n);
  //printf ("%s", n);
  int B;
  scanf ("%d", &B);
  int cnt=0;
  int c=0;
  int k=0;
  for (int i=strlen(n)-1;i>=0;i--) {

    if  (65<=n[i]) {
       if (n[i]>=97) {
        n[i]=toupper('n[i]');
        //printf ("%c", n[i]);
    }
    c=n[i]-'A'+10;

    }
    else {
        c=n[i]-'0';
    }
    //printf ("%d", n[i]);
    cnt =cnt+c*pow(A,k);
    k++;
  }
  //printf ("%d", cnt);
  int cn;
    int j=0;
    for (;cnt>0;j++) {
        cn = cnt%B;
        if (cn>=10) {
        cn=cn-10+'A';

        }
        else {
            cn=cn+'0';
        }
        a[j]=cn;
        cnt=cnt/B;
    }
    j--;
     while (j>=0) {
        printf ("%c", a[j--]);
      }

  return 0;

}
