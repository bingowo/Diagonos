#include <string.h>
#include <stdio.h>
#define ll long long

char s[10086];//十六进制数  
char t[10086];//二进制数 
int tot ;

inline void read(){//读入 
 scanf("%s",s) ;
 int len = strlen(s);
 for(int i = 2 ; i < len ; ++ i){
  int num,n=8; 
  num = s[i]>='A' ? s[i]-'A'+10 : s[i]-'0';
  
  for(int j = 3 ; j >= 0 ; -- j){
   t[tot++] = (num&n ? 1 : 0)+'0'  ;
   n >>= 1 ; 
  }
 }
 
 return ;
}

ll pr,pi , a,b ;
//pr,pi是结果量，a,b是当前值 

inline void write(){
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
 for(int i = 0 ; i < tot ; ++ i){
  a = pr , b = pi ;
  pr = -a-b+t[i]-'0' ;
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
0x1907530C03281D582  1089988679-2118137895i 
*/