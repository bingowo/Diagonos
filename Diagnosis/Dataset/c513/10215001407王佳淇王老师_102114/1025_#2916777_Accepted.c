#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
 char c[1000];
 int num;
}STR;
int count(char*c){
 int p[27]={0};
 int co=0;
 for(int v=0;v<strlen(c);v++){
  p[c[v]-'A']++;
 }
 for(int l=0;l<27;l++){
  if(p[l]>0) co++;
 }
 return co;
}
int cmp(const void*a,const void*b){
 int a1=((STR*)a)->num,b1=((STR*)b)->num;
 if(a1==b1) return strcmp(((STR*)a)->c,((STR*)b)->c);
 else return (b1>a1)?1:-1;
}
int main(){
 int T,N;
 STR str[1000];
 scanf("%d",&T);
 for(int i=0;i<T;i++){
  scanf("%d",&N);
 for(int j=0;j<N;j++){
  scanf("%s",str[j].c);
  str[j].num=count(str[j].c);
 }
 printf("case #%d:\n",i);
 qsort(str,N,sizeof(STR),cmp);
 for(int k=0;k<N;k++){
  printf("%s\n",str[k].c);
  memset(str[k].c,0,sizeof(STR));
 }

}
return 0;
}