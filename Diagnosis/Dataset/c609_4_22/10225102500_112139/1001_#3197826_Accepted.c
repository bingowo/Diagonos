#include <stdio.h>
#include <stdlib.h>

int main()
{int n;
 scanf("%d",&n);

 for(int i=0;i<n;i++){
 int a,b;
 scanf("%d %d",&a,&b);
 int c[1000]={0};
 if(a<0) {printf("-");
 a=-a;
 }
 int k=0;
 while(a/b!=0){
 c[k]=a%b;
 k++;
 a=a/b;


 }
 c[k]=a;
 int j=999;
 for( j=999;j>=0;j--){
  if(c[j]!=0) break;
 }
 for(;j>=0;j--){
        if(c[j]<=9){
 printf("%d",c[j]);}
 else printf("%c",c[j]-10+'A');

 }
printf("\n");

 }
 return 0;
}
