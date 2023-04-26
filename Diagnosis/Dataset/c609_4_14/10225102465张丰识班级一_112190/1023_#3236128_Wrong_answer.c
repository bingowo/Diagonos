#include <stdlib.h>
#include <stdio.h>
#include <string.h>
char u[19][100]={"pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen",
 "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu","uayet"};
 int find(char *z)
{
    for(int i = 0;i < 19;i++)
    {
        if  (strcmp(z,*(u+i))==0)
            return i;
    }
    return 0;
}
int cmp (const void*a,const void*b) {
     char *c=*(char **)a;
     char *d=*(char **)b;
     char m[3];
     char n[3];
     char q[10];
     char w[10];
     m[1]=c[strlen(c)-1];
     m[0]=c[strlen(c)-2];
     n[1]=d[strlen(d)-1];
     n[0]=d[strlen(d)-2];
     m[2]=n[2]='\0';
     int l=0;
     int cn=0;
     int cm=0;
     while (*(c+l)!=' ') {
        l++;
     }
     l++;
     while (*(c+l)!=' ') {
        q[cn]=*(c+l);
        l++;
        cn++;
     }
     l=0;
     while (*(d+l)!=' ') {
        l++;
     }
     l++;
     while (*(d+l)!=' ') {
        w[cm]=*(d+l);
        l++;
        cm++;
     }
     int x=atoi(m);
     int y=atoi(n);
     int g=find(q);
     int h=find(w);
     if (x!=y) {
        return x>y?1:-1;
     }
     else if (g!=h) {
        return g>h?1:-1;
     }
     else return c[0]>d[0]?1:-1;

}
void solve (int t) {
   printf ("case #%d:\n", t);
   int n;
   scanf ("%d", &n);
   getchar();
   char ch;
   char s[10000];
   char *p;
    int len=0;
    char b[10000][10000];
    char **a=&b[0][0];
  int i=0;
  int cnt=0;
   for (int k=0;k<n;k++) {
    while ((ch=getchar())!='\n') {
        s[cnt]=ch;
        cnt++;
    }
    s[cnt]='\0';
    cnt=0;
    len=strlen(s);

        p=(char *)malloc(len+1);        //动态分配邮件地址存储空间

        strcpy(p,s);

        *(a+i)=p;


        i++;
   }
   qsort (a,i,sizeof(a[0]),cmp);
  for (int r=0;r<i;r++) {
    printf ("%s\n", *(a+r));
}
}

int main () {
    int T;
    scanf ("%d", &T);
    for (int i = 0; i < T; i++)
        solve(i);
    return 0;
}
