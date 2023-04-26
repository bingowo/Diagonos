#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int print(char*a,int c,int d)
{if(strlen(a)==c-1) {printf("%s \n",a);return d;}
if(strlen(a)==c) {printf("%s\n",a);return d;}
if(strlen(a)<c-1){printf("%s ",a);return c-strlen(a)-1;}
if(strlen(a)>c){for(int i=0;i<c;i++) printf(" ");printf("\n");printf("%s ",a);return c-strlen(a)-1;}
}
int main()
{int n,k;
char c;
scanf("%d",&n);
getchar();
for(int i=0;i<n;i++)
{int j;
printf("case #%d:\n",i);
int t,h;
scanf("%d",&t);
getchar();
char m[2001];
gets(m);
char a[2000][36];
for(int k=0,j=0;k<strlen(m);k++)
{if(m[k]!=' ')
{for(h=0;m[k]!=' '&&k<strlen(m)h++,k++)
{a[j][h]=m[k];}
a[j][h]=0;
j++;}
}
int flag=t;
for(int one=0;one<j-1;one++)
{flag=print(a[one],flag,t);}
if(flag>=strlen(a[j-1])) printf("%s\n",a[j-1]);
else{for(int k=0;k<flag;k++) printf(" ");
printf("\n");
printf("%s\n",a[j-1]);}
}}
