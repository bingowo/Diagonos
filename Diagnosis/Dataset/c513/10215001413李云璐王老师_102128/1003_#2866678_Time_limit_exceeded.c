#include<stdio.h>
#include<stdlib.h>
void Sort(long long int *p, int n)
{ int compare(const void *a1, const void *a2)
  { int t=0,k=0;
  long long int a,b,l,w;
 l= a = *(long long int*)a1;
w= b = *(long long int*)a2;
     while (a!= 0)
     { if(a&1) t++;
      a>>=1;}
       while (b!= 0)
       {if(b&1) k++;
         b>>=1;}
     if (t>k) return -1;
     if (t<k) return 1;
     if(t==k){
         if(l<w) return -1;
        if(l>w) return 1;
         if(l==w) return 0;}

 }
 qsort(p,n,sizeof(long long int),compare);
}
 int main()
{

     int k,i,N,T;
    scanf("%d\n",&T);
   for(k=0;k<T;k++)
{ 
  scanf("%d\n",&N);
  long long int c[N];
  for (i=0;i<N;i++)
  scanf("%lld",&c[i]);
  Sort(c,N);
  printf("case #%d\n",k);
  for (i=0;i<N;i++)
  printf("%lld",c[i]);
  printf("\n");
}
return 0;}