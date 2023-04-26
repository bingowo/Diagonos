#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct score{
int num;
int sc;
int win;
int lose;
} Score;
int cmp(const void *e1,const void *e2){
Score o,p;
o=*(Score *)e1;
p=*(Score *)e2;
if(o.sc!=p.sc){
return p.sc-o.sc;
}else if(o.win!=p.win){
return p.win-o.win;
}else if(o.lose!=p.lose){
return o.lose-p.lose;
}else{
return o.num-p.num;
}
}


int main(){
int n=1,m=1;
while(1){
        int a[11]={0};
        int w[11]={0};
        int l[11]={0};
scanf("%d %d",&n,&m);
if(n==0&&m==0) break;
for(int i=0;i<m;i++){
int n1,n2,n3;
scanf("%d %d %d",&n1,&n2,&n3);
if(n3==1){
a[n1]+=3;
a[n2]-=1;
w[n1]++;
l[n2]++;
}else if(n3==-1){
a[n1]-=1;
a[n2]+=3;
l[n1]++;
w[n2]++;
}else if(n3==0){
a[n1]+=1;
a[n2]+=1;
}
}
Score b[10];
for(int i=0;i<n;i++){
b[i].num=i+1;
b[i].sc=a[i+1];
b[i].win=w[i+1];
b[i].lose=l[i+1];
}
qsort(b,n,sizeof(Score),cmp);
int j;
for(j=0;j<n-1;j++){
printf("%d ",b[j].num);
}
printf("%d\n",b[j].num);


}
return 0;



}
