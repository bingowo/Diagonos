#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int solve(int t) {
  printf ("case #%d:", t);
 char ch;

    char q[100];
    int j=0;
    int k=0;
    char s[500][100];
    while ((ch=getchar())!=EOF) {
    if    ((ch!=' ')&&(ch!='!')&&(ch!=',')&&(ch!='.')&&(ch!='?'))    q[k]=ch;

  else if ((ch==' ')||(ch=='!')||(ch==',')||(ch=='.')||(ch=='?')) {
      q[k]='\0';
      strcpy(*(s+j),q);

      k=0;
      j++;
  }
  k++;
  }
  j++;
  qsort (s,j,sizeof(s[0]),strcmp);

  int p=0;
  for (int l=0;l<j;l++) {
    if (strcmp(s[l],s[l+1])==0){
        for (;p<(strlen(s[l])-1);p++) {
            s[l][p]='a';
        }
            s[l][p]='1';
    }
  }
  qsort (s,j,sizeof(s[0]),strcmp);
  int g=0;
  int h=0;
  while (s[g][(strlen(s[g])-1)]=='1') {
    g++;
  }
  while (g<j) {
    printf ("%s ", s[g]);
    g++;
  }
}
int main () {
    int n;
    scanf ("%d", &n);
    for (int i = 0; i < n; i++)
        solve(i);
    return 0;
}
