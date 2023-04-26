#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Number{
int num;
int pos;
}number;
int cmp(const void* e1,const void* e2){
number m,n;
m=*(number*)e1;
n=*(number*)e2;
if(m.pos>n.pos){
return -1;
}else if(m.pos<n.pos){
return 1;
}else return m.num-n.num;



}

int main(){
int n1;
scanf("%d",&n1);
int* a=(int *)malloc(n1*sizeof(int));
for(int i=0;i<n1;i++){
scanf("%d",&a[i]);
}
int n2;
scanf("%d",&n2);
number* b=(number *)malloc(n2*sizeof(number));
for(int i=0;i<n2;i++){
scanf("%d",&b[i].num);
for(int j=0;j<n1;j++){
if(a[j]==b[i].num){
b[i].pos=n1-j;
break;
}else b[i].pos=-1;
}
}

qsort(b,n2,sizeof(number),cmp);
for(int i=0;i<n2;i++){
printf("%d ",b[i].num);

}
return 0;
}
