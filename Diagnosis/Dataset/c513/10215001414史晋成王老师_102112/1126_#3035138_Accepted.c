#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int cmp(const void*a, const void* b)
{
    int x,y;
    x=*(int*)a;
    y=*(int*)b;
    return y-x;
}
int main()
{ int n,i,j,m,k,sum1,sum2,c;
long long int a[10000];
long long int t=0,t1=0,t2=0;
  scanf("%d",&n);
  for(i=0;i<n;i++)
  { scanf("%lld",&a[i]);
    t^=a[i];
  }
  if(t!=0){printf("-1\n");return 0;}
  qsort(a,n,sizeof(a[0]),cmp);
  for(i=0;i<n-1;i++)
  {
      t2+=a[i];
      t1+=t2/100000000;
      t2%=100000000;
  }
  if(t1!=0) printf("%lld%08lld\n",t1,t2);
  else printf("%lld\n",t2);
}