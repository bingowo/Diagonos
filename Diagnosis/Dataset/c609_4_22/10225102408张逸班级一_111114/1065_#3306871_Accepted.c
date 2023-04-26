#include<stdio.h>
#include<stdlib.h>
char c[101];
double porish(){
   scanf("%s",c);
  if(c[0]=='+')return porish()+porish();
  else if(c[0]=='-')return porish()-porish();
  else if(c[0]=='*')return porish()*porish();
  else if(c[0]=='/')return porish()/porish();
  else return atof(c);
}
int main(){
   int t;
   scanf("%d",&t);
   for(int i=0;i<t;i++){
   printf("case #%d:\n%.6lf\n",i,porish());
   }
return 0;
}