#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Line{
int a[55];

}line;
int cmp(const void* e1,const void* e2){
line m,n;
m=*(line *)e1;
n=*(line *)e2;
int flag=0;
for(int i=0;i<55;i++){
if(m.a[i]==n.a[i]){
continue;
}else if(m.a[i]>n.a[i]){
return -1;
}else if(m.a[i]<n.a[i]){
return 1;
}

}



}
int main(){

int t;
scanf("%d",&t);
for(int i=0;i<t;i++){
int n;
scanf("%d",&n);
line* c=(line*)malloc(n*sizeof(line));
for(int j=0;j<n;j++){
int k=0;
while(1){
scanf("%d",&c[j].a[k]);
k++;
if(c[j].a[k-1]==-1) break;
}
}
qsort(c,n,sizeof(line),cmp);
for(int j=0;j<n;j++){
for(int k=0;k<55;k++){
if(c[j].a[k]!=-1) printf("%d ",c[j].a[k]);
else{printf("\n");
break;}
}

}
}
return 0;
}
