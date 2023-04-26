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
    int n1=*(int*)a;int n2=*(int*)b;
    if(cmp2(n1)==cmp2(n2))
        return n2-n1;
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
    int a[100];
    for(int x=0;x<N;x++)
    scanf("%d",&a[x]);
    qsort(a,N,sizeof(a[0]),cmp1);
     printf("case #%d:\n",i);
    for(int j=0;j<N;j++)
    printf("%d ",a[j]);

}
}
