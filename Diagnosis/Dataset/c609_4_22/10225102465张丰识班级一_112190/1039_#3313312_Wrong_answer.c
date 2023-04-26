#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int find2 (char s[],char t[]) {
int j=strlen(s)-1;
int k=strlen(t)-1;
for (;j>=0;j--) {
    if (k<0) break;
    if (s[j]==t[k]) k--;
    else k=strlen(t)-1;
}
return j;
}
int find1 (char s[],char t[]) {
int j=0;
int k=0;
for (;j<strlen(s);j++) {
        if (t[k]=='\0') break;
        if (s[j]==t[k]) k++;
        else k=0;

}
return j;
}
void solve(int t) {
printf ("case #%d:\n", t);
char p[80];
char p1[80];
char p2[80];
scanf ("%s", p1);
scanf ("%s", p2);
scanf ("%s", p);
int x=find1(p,p1);
int y=find2(p,p2);
int x1=find2(p,p1);
int y1=find1(p,p2);
int ans=y-x+1;
if (ans>0)
printf("%d\n", ans);
else if (x1-y1+1>0) printf ("%d\n", x1-y1+1);
else printf ("0");
}
int main () {
    int T;
    scanf ("%d", &T);
    for (int i = 0; i < T; i++)
        solve(i);
    return 0;
}
