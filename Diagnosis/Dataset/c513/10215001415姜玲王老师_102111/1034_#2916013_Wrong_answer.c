#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int main()
{double a[26];
char b[101];
int n;
scanf("%d",&n);
for(int i=0;i<n;i++)
{printf("case #%d:\n",i);
for(int t=0;t<26;t++)
{scanf("%lf",&a[t]);}
scanf("%s",b);
int  cmp(const void*c,const void*b)
{char*p1=(char*)c;
char*p2=(char*)b;
int q1,q2;
if((*p1)>='A'&&(*p1)<='Z') q1=(*p1)-'A';
else q1=*p1-'a';
if(*p2>='A'&&*p2<='Z') q1=*p2-'A';
else q2=*p2-'a';
if(a[q1]>a[q2]) return -1;
if(a[q1]<a[q2]) return 1;
if(q1!=q2) return q1-q2;
if(*p1!=*p2) return(*p2)-*p1;
return -1;
}
qsort(b,strlen(b),sizeof(b[0]),cmp);
printf("%s\n",b);
}
}
