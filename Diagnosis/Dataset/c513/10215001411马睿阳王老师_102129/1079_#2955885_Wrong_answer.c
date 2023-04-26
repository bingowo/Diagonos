#include<stdio.h>
#include<stdlib.h>
int cmp(const void*a,const void*b)
{if(*(long long int*)a>*(long long int*)b) return 1;
 else return -1;
}

int main()
{int n,m,T,L,U,k,i,j,x,w,z;
 scanf("%d",&T);
 for(i=0;i<T;i++)
 {long long a[2000];
  long long d[510005]={0};
  printf("case #%d:\n",i);
  scanf("%d%d",&n,&m);
  for(k=0;k<n;k++)
  {scanf("%lld",&a[k]);}
  for(x=1,z=0;x<=n;x++)
  {for(w=0;w<x;w++)
   {d[z]+=a[w];}
    z++;
   
   for(w=1;w<=n-x;w++)
   {d[z]=d[z-1]+a[n-1]-a[w-1];
    z++;
   }
  }
  qsort(d,z-1,sizeof(long long int),cmp);
  for(k=0;k<m;k++)
  {scanf("%d%d",&L,&U);
   long long sum=0;
   for(j=L-1;j<=U-1;j++)
   {sum+=d[j];}
   printf("%lld\n",d[z]);
  }
 }
 return 0;
}
