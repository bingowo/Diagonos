#include<stdio.h>
#include<math.h>
 struct data
{long long int a;
 int number;};

int cmp(const void*a,const void*b)
{ struct data d1,d2;
  d1=*((struct data*)a);
  d2=*((struct data*)b);
  if(d2.number!=d1.number)  return d2.number-d1.number;
  else 
  {if(d2.a>d1.a) return -1;
  else return 1;}
    
    
    
}
int main()
{int T,N,i,j,n,l;
 struct data p[10000];
 scanf("%d",&T);
 for (i=0;i<T;i++)
 {scanf("%d",&N);
  for(j=0;j<N;j++)
  {scanf("%lld",&p[j].a);
   p[j].number=0;
   int k=1;
   for (n=0;n<64=n=n+1)
    {   if (p[j].a&k) p[j].number++;
        k=k<<1;
    }
   
      
  }
  qsort(p,n,sizeof(p[0]),cmp);
  printf("case #%d:\n",&T);
  for (l=0;l<N;l++) printf("%d ",p[l]);  
 }
 
    
    
    
    
    
}