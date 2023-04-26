#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct st{
char str[30];
int num;
} St;
int cmp(const void* e1,const void* e2){
St p,q;
p=*(St *)e1;
q=*(St *)e2;
if(p.num!=q.num) return q.num-p.num;
else return strcmp(p.str,q.str);
}

int main(){
int t;
scanf("%d",&t);
for(int i=0;i<t;i++){
int n;
scanf("%d",&n);
St* a=malloc(n*sizeof(St));
for(int j=0;j<n;j++){
scanf("%s",a[j].str);
int b[127]={0};
int dif=0;
for(int k=0;(a[j].str)[k]!=0;k++){
char c;
c=(a[j].str)[k];
b[c]++;
}
for(int k=0;k<127;k++){
if(b[k]!=0) dif++;
}
a[j].num=dif;
}
qsort(a,n,sizeof(St),cmp);
printf("case #%d:\n",i);
for(int k=0;k<n;k++){
printf("%s\n",a[k].str);
}
}
return 0;

}
