#include <stdio.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
 int n,k,i,c;
 long double num=0;
 char s[100];
 scanf("%d",&n);
 for(k=0;k<n;k++){
  printf("case #%d:\n",k);
  scanf("%s",s);
  c=strlen(s);
  printf("len :%d \n",c);
  i=c-1;
  while(s[i]!='.'){
  num=num*0.125+(s[i]-'0');
  printf("num :%d \n",num);
  i--;}
  num*=0.125;
  printf("final num :%d \n",num);
  printf("%.50g\n",num);
  
 }
 return 0;
}