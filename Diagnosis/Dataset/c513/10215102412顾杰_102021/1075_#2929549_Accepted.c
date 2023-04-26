#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
int a[200][200];
char s[40000]="";
void f(int n,int m)
{
    char c[2]="";
    if(n==0&&m==0);
    else if(n==0){c[0]='R';strcat(s,c);f(n,m-1);}
    else if(m==0){c[0]='D';strcat(s,c);f(n-1,m);}
    else if(a[n-1][m]<a[n][m-1]){c[0]='D';strcat(s,c);f(n-1,m);}
    else {c[0]='R';strcat(s,c);f(n,m-1);}
}
int main()
{
   int m,n,i,j;
   char*p,*p0;
   scanf("%d%d",&n,&m);
   for(i=0;i<n;i++)for(j=0;j<m;j++){scanf("%d",&a[i][j]);
   if(i==0&&j==0);
   else if(i==0)a[i][j]+=a[i][j-1];
   else if(j==0)a[i][j]+=a[i-1][j];
   else a[i][j]+=a[i-1][j]<a[i][j-1]?a[i-1][j]:a[i][j-1];}
   f(n-1,m-1);
   p=s;p0=s+strlen(s)-1;
   while(p<p0){char c=*p;*p=*p0;*p0=c;p++;p0--;}
   printf("%d\n%s",a[n-1][m-1],s);
}
