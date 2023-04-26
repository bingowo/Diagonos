#include<stdio.h>
#include<math.h>
#include<stdlib.h>
typedef struct{
	int wi;
	int s;
	int num;
	int lo;
} p; 
int cmp1(const void* x,const void* y){
	int xx=(*(p*)x).s,yy=(*(p*)y).s;
	if(xx!=yy) return yy-xx;
	else if(((*(p*)y).wi!=(*(p*)x).wi)) return ((*(p*)y).wi>(*(p*)x).wi)?1:-1;
	else if(((*(p*)y).lo!=(*(p*)x).lo)) return ((*(p*)y).lo>(*(p*)x).lo)?-1:1;
	else return (*(p*)x).num>(*(p*)y).num;
}
int main(){
	int n,m,i,j;
	while(1){
		scanf("%d%d",&n,&m);
		if(n==0 && m==0) break;
		p t[15];
		for(j=0;j<n;j++){
			t[j].num=j+1;
			t[j].s=0;
			t[j].wi=0;
			t[j].lo=0;
			//printf("t=%d\n",t[j].num);
		}
		for(i=0;i<m;i++){	
			int a,b,si;
			scanf("%d%d%d",&a,&b,&si);
			if(si==0){
				t[a-1].s++;
				t[b-1].s++;
			}
			else if(si==1){
				t[a-1].s+=3;
				t[b-1].s--;
				t[a-1].wi++;
				t[b-1].lo++;
			}
			else{
				t[b-1].s+=3;
				t[a-1].s--;
				t[b-1].wi++;
				t[a-1].lo++;
			}
		}
		qsort((void*)t,n,sizeof(p),cmp1);
		for(j=0;j<n;j++){
			printf("%d ",t[j].num);
		}
		printf("\n");
	}
} 