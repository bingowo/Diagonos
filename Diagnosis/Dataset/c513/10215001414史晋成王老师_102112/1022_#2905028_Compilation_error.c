#include<stdio.h>
#include<stdlib.h>
int cmp(const void*a,const void*b)
{char s1[10000],s2[10000];
s1=(char*)a;
s2=(char*)b;
}
int main()
{int n,i,len; char **email;
char s[1000001],*p;
scanf("%d",&n); 
email=(char**)malloc(sizeof(char*)*n);
for(i=0;i<n;i++)
{scanf("%s",s);
len=strlen(s);
p=(char*)malloc(len+1);
strcpy(p,s);
*(email+i)=p;
}
 qsort(s,n,sizeof(s[0]),cmp);   
}