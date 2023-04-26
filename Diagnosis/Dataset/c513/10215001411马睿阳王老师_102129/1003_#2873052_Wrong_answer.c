#include<stdio.h>
#include<stdlib.h>
int compare(const void*a1,const void*a2)
{ int t=0,k=0,e=0,m=0;
  long long int a,b,l,w;
l=a=*(long long int*)a1;
w=b=*(long long int*)a2;
while(a!=0&&e<64)
{if(a&1)
{ t++;
  a>>=1;
}e++;}
while(b!=0&&k<64)
{if(b&1)
 {b>>=1;
  m++;}
  k++;
 }
if(t>m) return -1;
else if(t<m)  return 1;
else if(l>w) return 1;
else if(l<=w) return -1;

           
}

void sort(long long int*p,int n)
{qsort(p,n,sizeof(long long int),compare);
return 0;}

int main()
{int k,T;
 long long int N,i;
 scanf("%d",&T);
 for(k=0;k<T;k++)
{ scanf("%lld",&N);
  long long int c[N];
  for(i=0;i<N;i++)
  {scanf("%lld",&c[i]);
   sort (c,N);
   printf("case #%d:\n%lld\n",k,c[i]);
    return 0;
  }

 }
}
