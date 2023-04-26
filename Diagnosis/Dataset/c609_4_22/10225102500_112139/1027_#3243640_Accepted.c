#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct stu{
char num[12];
int score;
} Stu;
int cmp(const void* e1,const void* e2){
Stu p,q;
p=*(Stu *)e1;
q=*(Stu *)e2;
if(p.score!=q.score) return q.score-p.score;
else return strcmp(p.num,q.num);
}
int main(){
int t;
scanf("%d",&t);
for(int i=0;i<t;i++){
 int N,M,G;
 scanf("%d %d %d",&N,&M,&G);
 int *point=malloc((M+1)*sizeof(int));
 for(int j=1;j<=M;j++){
scanf("%d",&point[j]);
 }
 Stu * a=malloc(N*sizeof(Stu));
 for(int j=0;j<N;j++){
 char c;
 a[j].score=0;
 scanf("%s",a[j].num);
 int times;
 scanf("%d",&times);
 for(int k=0;k<times;k++){
 int l;
 scanf("%d",&l);
 a[j].score+=point[l];
 }


 }
 qsort(a,N,sizeof(Stu),cmp);
 int number=0;
 for(int j=0;j<N;j++){
 if(a[j].score>=G) number++;
 }
 printf("case #%d:\n%d\n",i,number);
 for(int j=0;j<N;j++){
 if(a[j].score>=G){
 printf("%s %d\n",a[j].num,a[j].score);
 }
 }

}
return 0;
}
