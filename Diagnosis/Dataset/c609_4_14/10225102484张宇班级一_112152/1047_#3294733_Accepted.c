#include <stdio.h>
#include <stdlib.h>
#define N 95
void mul(int *pls,int x){
  int carry=0;
  int t=0;
  for(int i=0;i<N;i++){
    t=pls[i]*x+carry;
    pls[i]=t%10;
    carry=t/10;
    }

}
int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        int a;int n;
        scanf("%d%d",&a,&n);
        int pls[N]={0};
        pls[0]=a;
        printf("case #%d:\n",i);
        if(n==0)printf("1");
        else{
        for(int j=1;j<n;j++)
        {
         mul(pls,a);}
        int k=N-1;
        for(;k>=0;k--){
            if(pls[k]==0);
            if(pls[k]!=0)break;
            }
        for(;k>=0;k--){
            printf("%d",pls[k]);
        }
   }printf("\n");
  }return 0;
}
