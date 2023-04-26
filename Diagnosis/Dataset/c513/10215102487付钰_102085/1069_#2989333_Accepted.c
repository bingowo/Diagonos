#include<stdio.h>
#include<math.h>
int IsPali(int num,int a[]){
    int j=0,i,b;
    while(num>0){
        a[j]=num%10;
        num=num/10;
        j++; 
 }
    j=j-1;
    for(i=0;i<=(int)(j+1)/2;i++){
    if(a[i]!=a[j-i])
    return -1;
 }
 return 1; 
}
int Reve(int num,int a[]){
    int j=0,i,k,sum=0;
    while(num>0){
  
    a[j]=num%10;
    num=num/10;
    j++; 
}
    j -=1;
    for(i=0,k=j;i<=j;i++,k--){
    sum +=a[i]*pow(10,k);
 }
    return sum;
}
int main(){
    int M,arr[10]={0},T,x=0;
    scanf("%d",&M);
    int N=Reve(M,arr);
   do{
     T=M+N;
     M=T;
     N=Reve(M,arr);
     x++;
 }while(IsPali(T,arr)!=1);
 printf("%d %d\n",x,T);
 return 0; 
}