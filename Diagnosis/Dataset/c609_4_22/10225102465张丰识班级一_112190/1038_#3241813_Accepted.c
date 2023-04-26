#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int solve(int t) {
  printf ("case #%d:\n", t);

 char ch;

    char q[100];
    int j=0;
    int k=0;
    char s[500][100];
     for (int h=0;h<strlen(q);h++) {
        q[h]='0';
    }
    for (int u=0;u<500;u++) {
        for (int v=0;v<100;v++) {
            s[u][v]='0';
        }
    }
    while ((ch=getchar())!='\n') {
    if    (islower(ch))   { q[k]=ch;
    k++;
    }

  else  { if (k) {
      q[k]='\0';
      strcpy(*(s+j),q);

      k=0;
      j++;
  }
  }

  }
  if (k) {
      q[k]='\0';
      strcpy(*(s+j),q);

      k=0;
      j++;
  }
  j++;
  qsort (s,j,sizeof(s[0]),strcmp);

  int p=0;
  for (int l=0;l<j;l++) {
    if (strcmp(s[l],s[l+1])==0){
        s[l][0]='0';
    }
  }

  int g=0;
  int h=0;
  while (g<j) {
  if (s[g][0]=='0') {
    g++;
  }
  else {
    printf ("%s ", s[g]);

    g++;
  }
}
printf ("\n");
}
int main () {
    int n;
    scanf ("%d", &n);
    getchar ();
    for (int i = 0; i < n; i++)
        solve(i);
    return 0;
}
