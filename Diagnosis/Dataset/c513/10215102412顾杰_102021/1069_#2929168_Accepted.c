#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
int f(int x)
{
    char s[20],*p,*p0;
    sprintf(s,"%d",x);
    p=s;p0=s+strlen(s)-1;
    while(p<p0){if(*p!=*p0)return 1;p++;p0--;}
    return 0;
}
int main()
{
   int n,m,s,k=0;
   char sm[20],*p,*p0;
   scanf("%d",&n);
   do{
    sprintf(sm,"%d",n);
    p=sm;p0=sm+strlen(sm)-1;
    while(p<p0){char t=*p;*p=*p0;*p0=t;p++;p0--;}
    m=atoi(sm);
    s=m+n;
    n=s;
    k++;
    //printf("%d %d",k,s);
   }while(f(s));
   printf("%d %d",k,s);
}
