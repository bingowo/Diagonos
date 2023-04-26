#include <stdio.h>
void solve(int t) {
  printf ("case #%d:\n", t);
  char n[100];
  scanf ("%s", n);
  int cnt=0;
  int cmp=0;
  for (int j=0;j<strlen(n)-1;j++) {
    if (n[j]=='1') {
        cnt=pow(3,(strlen(n)-1-j));
        cmp=cmp+cnt;
        cnt=0;
        continue;
    }
    else if (n[j]=='0') {
        cnt=0;
        cmp=cmp+cnt;
        cnt=0;
        continue;
    }
    else if (n[j]='-') {
        cnt=-pow(3,(strlen(n)-1-j));
        cmp=cmp+cnt;
        cnt=0;
        continue;
    }
}
printf ("%d\n", cmp);

}
int main () {
    int T;
    scanf ("%d", &T);
    for (int i = 0; i < T; i++)
        solve(i);
    return 0;
}
