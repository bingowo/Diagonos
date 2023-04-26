#include<stdio.h>
int main(){
 int T,i,j;
 scanf("%d",&T);
 for(i=0;i<T;i++){
 int arr[9],k=0,l;
 for(j=0;j<9;j++){
  scanf("%d",&arr[j]);
 }
 for(j=0;j<9;j++){
  if(arr[j]!=0){
   l=j;
  break;
 }
 
 }
 if(j==9)
 k=1;
 printf("case #%d:\n",i);
 for(j=0;j<7;j++){
  if(arr[j]==0){
  continue;
 }
  else if(arr[j]<0){
      if(arr[j]==-1)
      printf("-x^%d",8-j);
      else if(arr[j]!=-1)
      printf("%dx^%d",arr[j],8-j);
      
  }
  else if(arr[j]>0){
   if(arr[j]==1&&j==0)
   printf("x^8");
   else if(arr[j]==1&&j!=0&&j!=l)
   printf("+x^%d",8-j);
   else if(arr[j]==1&&j!=0&&j==l)
   printf("x^%d",8-j);
   else if(arr[j]!=1&&j==0)
   printf("%dx^8",arr[j]);
   else if(arr[j]!=1&&j!=0&&j!=l)
   printf("+%dx^%d",arr[j],8-j); 
   else if(arr[j]!=1&&j!=0&&j==l)
   printf("%dx^%d",arr[j],8-j); 
  }
 }
 if(arr[7]>0&&arr[7]==1&&l!=7)
 printf("+x");
 else if(arr[7]>0&&arr[7]==1&&l==7)
 printf("x");
 else if(arr[7]>0&&arr[7]!=1&&l!=7)
 printf("+%dx",arr[7]);
 else if(arr[7]>0&&arr[7]!=1&&l==7)
 printf("%dx",arr[7]);
 else if(arr[7]<0&&arr[7]==-1)
 printf("-x");
 else if(arr[7]<0&&arr[7]!=-1)
 printf("%dx",arr[7]);
 if(arr[8]==0&&k==1)
 printf("0");
 else if(arr[8]>0&&l!=8)
 printf("+%d",arr[8]);
 else if(arr[8]>0&&l==8)
 printf("%d",arr[8]);
 else if(arr[8]<0)
 printf("%d",arr[8]);
 printf("\n");
}
return 0;
}