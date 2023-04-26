#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int FindSubstrFromLeft(char*s,char*s1)
{  char* p=strstr(s,s1);
    return p==0?-1:p-s;
}
        
int FindSubstrFromRight(char*s,char*s1)
{  char*p=s,*p1=0;
    while ((p1=strstr(p,s1))!=0) p=p1+1;
    return p-s-1;
}
int max(int a,int b)
{return a>b?a:b;}
int main()
{ int t,n,i,j,z,b,c,count1,count2,x,a,max1; char s[100],s1[100],s2[100];
scanf("%d\n",&n);
for(i=0;i<n;i++)
{ gets(s1); a=strlen(s1);
  gets(s2); b=strlen(s2);
  gets(s); c=strlen(s);
  j=0;
  count2=FindSubstrFromRight(s,s2);
  count1=FindSubstrFromLeft(s,s1);
    max1=0;
  if (count1!=-1&&count2!=-1)
  {max1=max(max1,count2-count1-strlen(s1));
   count1=FindSubstrFromLeft(s,s2);
   count2=FindSubstrFromRight(s,s1);
  max1=max(max1,count2-count1-strlen(s2));}
  printf("case #%d:\n",i);
  printf("%d %d %d\n",count2,count1,max);
}
    
}