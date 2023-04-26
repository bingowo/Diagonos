#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int f(int n,int m)
{ if(n<m) return 0;
  if(n==m) return 1;
  else
  return 2*f(n-1,m)-f(n-1-m,m)+pow(2,m-1-m);
    
}
int main()
{ int a[10000],b[10000],i,j;
i=0;j=0;
while(scanf("%d %d",&a[i],&b[i])!=EOF)
{ if(a[i]==-1&&b[i]==-1) break;
 else if(a[i]!=-1&&b[i]!=-1) 
{ printf("%d\n",f(a[i],b[i]));
 i++;
    }
}

}