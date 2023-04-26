#include <stdio.h>
#include <stdlib.h>
typedef struct{long long int a;int b;}ANS;
int cmp(const void* a,const void* b){
    ANS* A = (ANS*) a;
    ANS* B = (ANS*) b;
    if (A->b == B->b) {
  if (A->a > B->a)
   return 1;
  else
   return -1;
 }
 else {
  if (A->b > B->b)
   return -1;
  else
   return 1;
 }
}
int main() {
 int T,x = 0;
 scanf("%d", &T);
 while (T--) {
  int n;
  scanf("%d",&n);
  ANS answer[n];
  for(int i = 0;i < n;i++){
  	scanf("%lld",&answer[i].a);
  	int temp = 0,tool = 1;
    long long int cop = answer[i].a;
  	do{
        if(cop&1)
            temp++;
	  }while(cop=cop>>1);
	answer[i].b = temp;
  }
  qsort(answer,n,sizeof(answer[0]),cmp);
  printf("case #%d:\n", x);
  x++;
  for(int i = 0;i < n;i++)
    printf("%lld ",answer[i].a);
 }
 return 0;
}
