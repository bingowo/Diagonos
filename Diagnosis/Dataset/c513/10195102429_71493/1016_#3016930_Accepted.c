#include <stdio.h>
#include <stdlib.h>

int main(){
 int n,r,num=0;
 int ans[10005];
 scanf("%d%d",&n,&r);
 if(n==0) printf("0");
 int temp=n;
 while(n!=0){
 int yu=n%r;
 int shang=n/r;
 if(yu<0){
 yu-=r;
 shang++;
 }
 n=shang;
 ans[num++]=yu;
 }
 for(int i=num-1;i>=0;i--){
 if(ans[i]<10){
 printf("%d",ans[i]);
 }
 else{
 printf("%c",ans[i]-10+'A');
 }
 }
 return 0;
}
