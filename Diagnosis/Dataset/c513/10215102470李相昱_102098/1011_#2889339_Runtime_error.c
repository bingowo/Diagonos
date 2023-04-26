#include <string.h>
#include <stdio.h>
#define ll long long

char s[10086];//十六进制数 
ll num ;//将十六进制数转化为十进制数存储 
char t[10086];
int tot ;

void read(){//读入 
 scanf("%s",s) ;
 int len = strlen(s);
 for(int i = 2 ; i < len ; ++ i){
  num *= 16;
  num += s[i]>='A' ? s[i]-'A'+10 : s[i]-'0';
 }
 while(num){
  t[tot++] = num&1  ;
  num >>= 1 ; 
 }//tot是二进制位数，t[]从0开始，是一个反向的二进制数； 
 return ;
}

ll pr,pi , a,b ;
//pr,pi是结果量，a,b是当前值 

void write(){
 if(pi == 0){
  printf("%lld\n",pr) ;
  return ;
 }
 if(pr != 0){
  printf("%lld",pr);
  if(pi > 0) printf("+") ;
 }
 if(pi == 1 || pi == -1){
  pi == 1 ? printf("i\n") : printf("-i\n") ;
  return ;
 }
 else printf("%lldi\n",pi);
}

int main(){
 read();
 for(int i = tot-1 ; i >= 0 ; -- i){
  ll a = pr , b = pi ;
  pr = -a-b+t[i] ;
  pi = a-b; 
   //pr + pi * i = (pr + pi * i) * (-1 + i) + num&1;
 }
 write();
 return 0 ;
}
/*
0x21  5-4i
0x2   -1+i
0x1C  -2
0x9  3+2i
*/