#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
void er(int x,char*s){
 int k=0,i,t;
 while(x!=0){
  s[k++]=x%2+'0';
  x=x/2;
 }
 s[k]='\0';
 
}
 int maxleng(char*s){
 char*p;
 char*r;
 p=s;
 int l=1,i;
 p=p+1;
 while(*p){r=p;
  for(i=1;*r&&(*r!=*(r-1));r++,i++);
  if(i>l) l=i;
  p=r+1;
 }
 return l;
 }
int main()
{ int i,T,j,x;
 char s[200];
 scanf("%d\n",&T);
 for(i=0;i<T;i++){
  scanf("%d",&x);
  printf("case #%d:\n",i);
  er(x,s);
  printf("%d\n",maxleng(s));
 }
 return 0;
}