#include <stdio.h>
#include <stdlib.h>
int cmp2(int n){
  int k,l;
  k=0;
  for(int z=0;z<64;z++)
  {
      l=(n>>z)&1;
      if(l==1)k++;
  }
  return k;


}
int cmp1(const void*a,const void*b)
{
    long long int n1=*(long long int*)a;long long int n2=*(long long int*)b;
    if(cmp2(n1)==cmp2(n2))
        {
            if(n1>n2)return 1;
            else if(n2>n1)return -1;
            else return 0;
        }
    else if(cmp2(n1)>cmp2(n2))
        return -1;
    else if(cmp2(n2)>cmp2(n1))
        return 1;
}
int main()
{
int T;
scanf("%d",&T);
for(int i=0;i<T;i++)
{   int N;
    scanf("%d",&N);
    long long int a[N];
    for(int x=0;x<N;x++)
    scanf("%lld",&a[x]);
    int leng=sizeof(a)/sizeof(a[0]);
    qsort(a,leng,sizeof(a[0]),cmp1);
     printf("case #%d:\n",i);
    for(int j=0;j<N;j++)
    printf("%lld ",a[j]);
    printf("\n");

}
}


