#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
typedef struct{int a;int k;}ak;
ak tab[100001][2];
int main()
{
   int a,n,m,x,k,i,ans;
  // memset(tab,0,100001*2*sizeof(tab[0][0]));
   tab[1][0].a=1;tab[2][0].k=1;tab[2][1].k=1;
   scanf("%d%d%d%d",&a,&n,&m,&x);
   n--;
   for(i=3;i<=n;i++)
   {tab[i][0].a=tab[i-1][0].a+tab[i-2][0].a;
   tab[i][0].k=tab[i-1][0].k+tab[i-2][0].k;
   tab[i][1].a=tab[i-1][0].a;tab[i][1].k=tab[i-1][0].k;
   }
   k=(m-a-tab[n][0].a*a)/(tab[n][0].k-1);
   if(x==1)printf("%d",a);
   else printf("%d",a-k+tab[x][0].a*a+tab[x][0].k*k);
}
