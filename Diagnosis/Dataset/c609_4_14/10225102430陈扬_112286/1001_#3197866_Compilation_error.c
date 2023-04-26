#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T,R,N;
    scanf("%d",&N);
    for(int i = 0;i<N;i++）{
        scanf("%d%d",&T,&R);
        while(T!=0）{
              if(T<0){
                printf("-");
              }
              int j = 0;
              int temp = 0;
              char arr[];
              temp=T%R;
              T=T/R;
              arr[j++]=temp;
              for(int k=j-1;k>=0;k--){
                printf("%s",arr[k]);
              }
              }
    }
    return 0;
}