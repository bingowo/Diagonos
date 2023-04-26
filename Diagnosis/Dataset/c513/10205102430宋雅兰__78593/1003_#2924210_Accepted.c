#include<stdio.h>
#include<stdlib.h>

int cmp(const void*p1,const void*p2)
{
  long long a=*(long long *)p1;
  long long b=*(long long *)p2;
  int an=0,bn=0;
  long long d=1;
  for(int k=0;k<64;k++){
      if(a&d)an++;
      if(b&d)bn++;
      d=d<<1;
  }
  if(an==bn)return a>b;//up
  return bn-an;//big to small
}
int main()
{
    int T,n,d;
    scanf("%d",&T);
    long long a[10001]={0};
    for(int i=0;i<T;i++)
    {
        scanf("%d",&n);
        for(int j=0;j<n;j++)
        {
            scanf("%lld",a+j);

        }
        qsort(a,n,sizeof(a[0]),cmp);
        printf("case #%d:\n",i);
        for(int j=0;j<n-1;j++)
        {
            printf("%lld ",a[j]);
        }
        printf("%lld\n",a[n-1]);
    }
    return 0;
}