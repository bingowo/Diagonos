#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<ctype.h>
int cmp(const void*a,const void*b)
{char*p1=(char*)a;
char*p2=(char*)b;
return strcmp(*p1,*p2);
}
int main()
{int n,k,j;
scanf("%d",&n);
char origin[2001];
char alpha[2001];
for(int i=0;i<n;i++)
{printf("case #%d:\n",i);
    gets(origin);
for(k=0,j=0;k<strlen(origin);k++)
{if(isalpha(origin[k]))alpha[j++]=origin[k];}
qsort(alpha,j,sizeof(alpha[0]),cmp);

for(k=0,j=0;k<strlen(origin);k++)
{if(isalpha(origin[k])) printf("%c",alpha[j++]);
else printf("%c",origin[k]);
}
printf("\n");}}
