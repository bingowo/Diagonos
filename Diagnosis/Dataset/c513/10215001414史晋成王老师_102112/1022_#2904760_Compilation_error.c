#include<stdio.h>
#include<stdlib.h>
int cmp(const void*a,const void*b)
{char s1[10000],s2[10000];
s1=(char*)a;
s2=(char*)b;
}
int main()
{int n,i; char s[10000][10000];
scanf("%d",&n); 
for(i=0;i<n;i++)
{scanf("%s",s[i]);
}
 qsort(s,n,sizeof(s[0]),cmp);   
}