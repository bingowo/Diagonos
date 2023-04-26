#include <stdio.h>
int main() {
 int a[21],b[21],i;
 a[0]=b[0]=0;a[1]=b[1]=1;
 for(i=2;i<=20;i++){
 a[i]=a[i-1]+b[i-1];
 b[i]=a[i]-b[i-2];
 }
 while(scanf("%d",&i)!=EOF&&i!=-1){
 printf("%d\n",a[i]+b[i]);
 }
 return 0;
}
