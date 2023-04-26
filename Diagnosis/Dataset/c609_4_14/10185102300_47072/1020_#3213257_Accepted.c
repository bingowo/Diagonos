#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int num(char*s)
{  while (*s) 
     if (isdigit(*s))  { int r=0; while (isdigit(*s)) r=r*10+*s++-'0'; return r; } 
     else s++;
   return -1;
}

 int strnumcmp(const void* e1,const void* e2)
 { char* s1=(char*)e1,*s2=(char*)e2; int delta;
   return (delta=num(s1)-num(s2)) ? delta: strcmp(s1,s2);
 }
int main()
{ int n=0,i; char  a[100][31];
  while (scanf("%s",a+n)!=EOF)  n++;
  qsort(a,n,sizeof(a[0]),strnumcmp);
  for(i=0;i<n;i++) printf("%s%c",a[i],i<n-1?' ':'\n');

   return 0;
}