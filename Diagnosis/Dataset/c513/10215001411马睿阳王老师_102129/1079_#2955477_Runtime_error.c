#include<stdio.h>
#include<stdlib.h>

int cmp(const void*a,const void*b)
{int x,y;
 x=*(int *)a;
 y=*(int *)b;
 if(x>y) return 1;
 else return -1;
}

int main()
{int T,n,m,k,t=0,i,j,L,U,g,h,x,y;
 int s[1005],a[1005],b[1005];
 scanf("%d",&T);
 for(k=0;k<T;k++)
 {scanf("%d %d",&n,&m);
  for(j=0;j<n;j++)
  scanf("%d ",&s[j]);
  while(t<m)
  {scanf("%d %d",&L,&U);
   t++;}

   //当子数组元素个数为1
 if(n==1)
   {a[g]=0;
   for(j=0,g=0;g<n;j++,g++)
   a[g]=s[j];
   qsort(a,n,sizeof(int),cmp);
   for(g=0,h=0;h<n;g++,h++)
   b[h]=a[g];
   }

   //当子数组元素个数为2时
 if (n==2)
   {a[g]=0;
   for(j=1,g=0;g<n-1;j++,g++)
    a[g]=s[j]+s[j-1];
    qsort(a,n-1,sizeof(int),cmp);
   for(g=0,h=n;g<n-2;g++,h++)
    b[h]=a[g];
   }

   //当子数组元素个数为x时
 else
   {for(x=3;x<=n;x++)
       {a[g]=0;
       for(j=1,g=0;g<n-x+1;j++,g++)
          {for(j=0;j<x;j++)
           a[g]+=s[j];
           qsort(a,n-x+1,sizeof(int),cmp);
           y=(1+x)*(-x+2)/2;
           for(g=0,h=y;g<n-x+1;g++,h++)
           b[h]=a[g];
          }
       }
   }
 long long int v=0;
 for(h=L-1;h<=U-1;h++)
 {v+=b[h];}
 printf("case #%d:\n",k);
 printf("%lld",v);
 }
 return 0;
}
