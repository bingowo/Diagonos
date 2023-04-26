#include <stdio.h>
#include <stdlib.h>
typedef struct{
	int a,b,c;              //胜a负b积分c 
	int d;                  //第几组 
}sta;
void f1(int x,int y,int judge,sta num[]){
	if(judge==1){
		num[x-1].a+=1;num[x-1].c+=3;
		num[y-1].b+=1;num[y-1].c-=1;
	}else if(judge==-1){
		num[y-1].a+=1;num[y-1].c+=3;
		num[x-1].b+=1;num[x-1].c-=1;
	}else{
		num[x-1].c+=1;
		num[y-1].c+=1;
	}
}
int f2(const void *a,const void *b){
	sta *x=(sta*)a,*y=(sta*)b;
	if(x->c!=y->c){
		return y->c-x->c;
	}else if(x->a!=y->a){
		return y->a-x->a;
	}else if(x->b!=y->b){
		return x->b-y->b;
	}else{
		return x->d-y->d;
	}
}
int main(){
	int m,n,i;
	int x,y,judge;
	while(scanf("%d%d",&n,&m)!=EOF){
	    if(n==0&&m==0)break;
		sta* num=(sta*)malloc(n*sizeof(sta));
		for(i=0;i<n;i++){
			num[i].a=num[i].b=num[i].c=0;
			num[i].d=i+1;
		} 
		for(i=0;i<m;i++){
			scanf("%d %d %d",&x,&y,&judge);
			f1(x,y,judge,num);
		}
		qsort(num,n,sizeof(sta),f2);
		for(i=0;i<n;i++){
			printf("%d%c",num[i].d,(i==n-1)?'\n':' ');
		}
	}
}