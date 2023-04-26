#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n,m; 
struct node{
 int id,cnt,win,lose;
}A[1005];
int cmp(const void * a, const void * b){
 struct node x=*(struct node*)a,y=*(struct node*)b;
 if(x.cnt!=y.cnt) return y.cnt-x.cnt;
 else if(x.win!=y.win) return y.win-x.win;
 else if(x.lose!=y.lose) return x.lose-y.lose;
 else return x.id-y.id;
}
int main() {
 while(~scanf("%d%d",&n,&m)){
  if(n==0) break;
  for(int i=1;i<=n;i++) A[i].win=A[i].lose=A[i].cnt=0,A[i].id=i;
  for(int i=1;i<=m;i++){
   int a,b,x;
   scanf("%d%d%d",&a,&b,&x);
   if(x==1) A[a].cnt+=3,A[a].win++,A[b].cnt-=1,A[b].lose++;
   else if(x==-1) A[b].cnt+=3,A[b].win++,A[a].cnt-=1,A[a].lose++;
   else A[b].cnt++,A[a].cnt++;
  }
  qsort(A+1,n,sizeof(struct node),cmp);
  for(int i=1;i<=n;i++) printf("%d ",A[i].id);
  puts("");
 }
 return 0;
}