#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct stu{
    char id[12];
    int rank;
}stud;
int cmp(const void*a1,const void*a2){
    stud*p1=(stud*)a1,*p2=(stud*)a2;
    if(p1->rank!=p2->rank)return p2->rank-p1->rank;
    else return strcmp(p1->id,p2->id);
}
int main(){
int t;
scanf("%d",&t);
for(int z=0;z<t;z++){
int n,m,g;
scanf("%d %d %d",&n,&m,&g);
int problem[m];stud student[n];
for(int i=1;i<=m;i++){
    scanf("%d",&problem[i]);
}
for(int i=0;i<n;i++){
    int num;
    scanf("%s%d",&student[i].id,&num);
    student[i].rank=0; int rank=0;
    for(int j=0;j<num;j++){
        int a;scanf("%d",&a);
        student[i].rank+=problem[a];
    }
}
qsort(student,n,sizeof(stud),cmp);
printf("case #%d:\n",z);int num=0;
for(int i=0;i<n;i++){
    if(student[i].rank>=g){
      num++;
      }}
printf("%d\n",num);
for(int i=0;i<n;i++){      
    if(student[i].rank>=g){
    printf("%s %d\n",student[i].id,student[i].rank);}
}
}
return 0;
}


