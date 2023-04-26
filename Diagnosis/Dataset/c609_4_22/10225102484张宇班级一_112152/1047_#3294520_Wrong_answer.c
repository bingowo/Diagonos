#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
        if(n==0)printf("0");
        else{
        for(int j=1;j<n;j++)
        {
         mul(pls,a);
        }
        int l=strlen(pls);
        for(int k=l;k>=0;k--){
            printf("%d",pls[k]);
        }
   }
}
}