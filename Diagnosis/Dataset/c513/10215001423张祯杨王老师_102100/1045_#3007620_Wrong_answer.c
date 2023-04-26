#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 100002
int min(int x,int y)
{
    if(x<=y) return x;
    else return y;
}

int main()
{  int n,judge=1,result,add;
   scanf("%d",&n);
   char a[N][101],b[N][101];
   for(int i=1;i<=n;i++) scanf("%s",a[i]);
   for(int q=1;q<=n;q++) simplify(q,a[q],a);
   int c[n],d[n];
   for(int i=1;i<=n;i++) c[i]=strlen(a[i]);
   for(int i=1;i<=n;i++) d[i]=strlen(b[i]);
   for(int i=1;i<=n;i++) add+=c[i];
   int t=1,y=2,g=0;
   for(int i=1;i<n;i++)
   { if(d[t++]==d[y++])
     {  if(b[i][g++]!=b[i+1][g++])
         judge=0;
     }
     if(d[t++]!=d[y++]) judge=0;
   }
   if(judge==0) printf("-1");
   if(judge!=0)
   { int s=add/n;
     result=min(add-n*s,n*(s+1)-add);
     printf("%d",result);
   }
   return 0;
}


int simplify(int x,char** a)
{ int len[N];
  char b[N][101];
  len[x]=strlen(a[x]);
  b[x][0]=a[x][0];
  int cnt=1;
  for(int i=0;i<len[x];i++)
  { if(a[x][i+1]!=a[x][i])
    { b[x][cnt]=a[x][i+1];
      cnt++;
    }
  }
   return b[x];
}


