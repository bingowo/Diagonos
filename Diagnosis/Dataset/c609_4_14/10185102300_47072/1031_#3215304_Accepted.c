#include <stdio.h>
#include <stdlib.h>
 

int cmp(const void* e1,const void*e2)
{ long long n1=*(long long*)e1, n2=*(long long*)e2;
  if (n1>n2) return 1;
  if (n1<n2) return -1;
  return 0;
    
}


int main()
{  int I,T;
    for(scanf("%d",&T),I=0;I<T;I++)
    {  int n,m,a[1000],i,bn=0,j,k,s,l,u;
       static long long b[500000];
       printf("case #%d:\n",I);
       scanf("%d%d",&n,&m);
       for (i=0;i<n;i++) scanf("%d",a+i);
  /***/     for (i=1;i<=n;i++)
  /***/         for (j=0;j<n-i+1;j++)
  /***/	       { s=0; for(k=j;k<j+i;k++) s+=a[k];
       b[bn++]=s;
	 }
     qsort(b,bn,sizeof(b[0]),cmp);
/*
     for (i=0;i<m;i++)
     { scanf("%d%d",&l,&u);
        long long s=0; for (k=l-1;k<u;k++) s+=b[k];
        printf("%lld\n",s);
      }
*/
     static long long bx[500001]={0};
     for (i=1;i<=bn;i++) bx[i]=bx[i-1]+b[i-1];

     for (i=0;i<m;i++)
     {  scanf("%d%d",&l,&u);
        printf("%lld\n",bx[u]-bx[l-1]);
      }
        
        
        
    }

    return 0;
}