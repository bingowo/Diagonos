#include<stdio.h>
#include<string.h>

int main(){
 int T;
 scanf("%d",&T);
 int n=0;
 while(T--){
  char a[1000];
  scanf("%s",a);
  int o=0;
  for(int i=0;i<strlen(a);i++){
   if(a[i]=='-')
   o=o*3-1;
   else if(a[i]=='0')
   o=o*3;
   else
   o=o*3+1;
  }
  printf("case #%d:\n%d\n",n,o);
  n++;
 }
 return 0; 
} 