#include <stdio.h>
#include <stdlib.h>
void Trans(int x,int y){
    while(y<10){
              if(x<0){
                x=-x;
                printf("-");
              }
              int j = 0;
              int temp = 0;
              int arr[32];
              while (x!=0){
              temp=x%y;
              x=x/y;
              arr[j++]=temp;
              }
              for(int k=j-1;k>=0;k--){
                printf("%d",arr[k]);
              }
              }
    if(y>=10){
              if(x<0){
                x=-x;
                printf("-");
              }
              int j = 0;
              int temp = 0;
              int arr[30];
              while(x!=0){
              temp=x%y;
              x=x/y;
              arr[j++]=temp;
              }
              char ALP[30]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
              for(int k=j-1;k>=0;k--){
                if(arr[k]>=10){
                    printf("%c",ALP[arr[k]-10]);
                }
                else {
                    printf("%d",arr[k]);
                }
              }
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    for (int i=0;i<T;i++){
        scanf("%d%d",&N,&R);
        Trans(N,R);
    }
    return 0;
}

