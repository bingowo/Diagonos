#include<stdio.h>
#include<stdlib.h>
 struct data
{long long int a;
 int number;
};

int cmp(const void*a,const void*b)
{ struct data d1,d2;
  d1=*((struct data*)a);
  d2=*((struct data*)b);
  if(d2.number!=d1.number)  return d2.number-d1.number;
  else 
  {if(d1.a>d2.a) return 1;
  else return -1;}
}
int main()
{int T,N,i=0,j,m,l; long long int k;

 scanf("%d",&T);
 while(i<T)
 { struct data p[10000];
   scanf("%d",&N);       
  for(j=0;j<N;j++)
  {scanf("%lld",&p[j].a);
   p[j].number=0;
    k=1;
   for (m=0;m<64;m=m+1)
    {   if (p[j].a&k) p[j].number++;
        k=k<<1;
    }
   
      
  }
  qsort(p,N,sizeof(p[0]),cmp);
  printf("case #%d:\n",i);
  for (l=0;l<N-1;l++) printf("%lld ",p[l].a); 
  printf("%lld\n",p[l].a);
  i++;
 }
 
    
    
    
    
    return 0;
}