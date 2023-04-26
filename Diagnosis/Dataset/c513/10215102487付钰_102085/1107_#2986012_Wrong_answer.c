#include <stdio.h>
#include <stdlib.h>

int main(){
 int T,i,arr[3][3],j,k,brr[3][3],x,y;
 scanf("%d",&T);
 for(i=0;i<T;i++){
  for(j=0;j<3;j++){
   for(k=0;k<3;k++){
    scanf("%d",&arr[j][k]);
   }
  }
  for(j=0;j<3;j++){
   for(k=0;k<3;k++){
    brr[j][k]=1;
   }
  }
  for(j=0;j<3;j++){
   for(k=0;k<3;k++){
    if(arr[j][k]%2!=0){
     for(x=k-1;x<=k+1;x++){
      if(x>=0&&x<=2){
       if(brr[j][x]==0)
       brr[j][x]=1;
       else
       brr[j][x]=0;
      }
     }
      for(y=j-1;y<=j+1;y++){
       if(y>=0&&y<=2){
        if(brr[y][k]==0)
        brr[y][k]=1;
        else
        brr[y][k]=0;
       }
      }
      if(brr[j][k]==0)
      brr[j][k]=1;
      else
      brr[j][k]=0;
     }
    }
   }
   printf("case #%d:\n",i);
   for(j=0;j<3;j++){
    for(k=0;k<3;k++){
     if(k<2)
     printf("%d ",brr[j][k]);
     else
     printf("%d",brr[j][k]);
    }
   }
 }
 return 0;
}
