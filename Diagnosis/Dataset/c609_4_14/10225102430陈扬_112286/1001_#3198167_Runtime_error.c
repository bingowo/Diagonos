#include <stdio.h>
#include <stdlib.h>
void Trans(int x,int y){
    while(x!=0&&y<10){
              if(x<0){
                x=-x;
                printf("-");
              }
              int j = 0;
              int temp = 0;
              char arr[32];
              temp=x%y;
              x=x/y;
              arr[j++]=temp;
              for(int k=j-1;k>=0;k--){
                printf("%s",arr[k]);
              }
              }
    if(x!=0&&y>=10){
              if(x<0){
                x=-x;
                printf("-");
              }
              int j = 0;
              int temp = 0;
              char arr[26];
              temp=x%y;
              x=x/y;
              arr[j++]=temp;
              char ALP[]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
              for(int k=j-1;k>=0;k--){
                if(arr[k]>=10){
                    printf("%s",ALP[arr[k]-10]);
                }
                else {
                    printf("%d",arr[k]);
                }
              }
    }
}
int main()
{
    Trans(12,15);
    return 0;
}
