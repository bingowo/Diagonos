#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct team{
	int num;
	int s;
	int v;
	int l;
}T;
int cmp(const void *x, const void *y){
	T xx=*(T*)x; 
	T yy=*(T*)y;
	if(xx.s>yy.s) return -1;
	if(xx.s<yy.s) return 1;
	if(xx.s==yy.s){
		if(xx.v>yy.v) return -1;
		if(xx.v<yy.v) return 1;
		if(xx.v==yy.v){
			if(xx.l<yy.l) return -1;
			if(xx.l>yy.l) return 1;
			if(xx.l==yy.l){
				if(xx.num>yy.num) return 1;
				if(xx.num<yy.num) return -1;
			}
		}
	}
}
int main(){
	while(1){
		int n,m;
		scanf("%d %d",&n,&m);
		if(n==0 && m==0) return 0;
		T t[11];
		t[0].num=-1;
		t[0].s=-1111;
		for(int y=1;y<11;y++){
			if(y>n){
				t[y].num=-1;
				t[y].s=-1111;
			}
			t[y].num=y;
			t[y].s=0;
			t[y].v=0;
			t[y].l=0;
		}
		int i=0;
		for(i=0;i<m;i++){
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			t[a].num=a;
			t[b].num=b;
			if(c==1){
				t[a].s+=3;
				t[a].v++;
				t[b].s-=1; 
				t[b].l++;
			}
			if(c==-1){
				t[a].s-=1;
				t[a].l++;
				t[b].s+=3; 	
				t[b].v++;			
			}
			if(c==0){
				t[a].s+=1;
				t[b].s+=1; 				
			}			
		}
		qsort(t,n+1,sizeof(T),cmp);
		for(int y=0;y<n;y++){
			printf("%d ",t[y].num);
		}
		printf("\n");
	}
return 0;
}