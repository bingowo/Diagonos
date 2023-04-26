#include<stdio.h>
char m[22][20]={“pop”, “no”, “zip”, “zotz”, “tzec”, “xul”, “yoxkin”, “mol”, “chen”, “yax”, “zac”, “ceh”, “mac”, “kankin”, “muan”, “pax”, “koyab”, “cumhu”,”uayet”};
struct date{
int y,d,m,dd;
} a[10010];
char s[300];
void read(int i){
scanf(“%d”,&a[i].d);
char c;
scanf(“%c”,&c);
scanf(“%s”,s);
int ii;
for (ii=0;ii<20;ii++) if (strcmp(m[ii],s)==0) break;
a[i].m=ii;
scanf(“%d”,&a[i].y);
a[i].dd=a[i].d;
for (int ii=0;ii<a[i].m;ii++) a[i].dd+=20;
}
bool cmp(date p1,date p2){
return (p1.y<p2.y || (p1.y==p2.y && p1.dd<p2.dd));
}
int main()
{
int T,n;
scanf(“%d”,&T);
for (int ii=0;ii<T;ii++){
scanf(“%d”,&n);
for (int i=0;i<n;i++) read(i);
sort(a,a+n,cmp);
printf(“case #%d:\n”,ii);
for (int i=0;i<n;i++) printf(“%d. %s %d\n”,a[i].d,m[a[i].m],a[i].y);
}
}