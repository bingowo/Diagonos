#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
typedef struct{
	int x,y,power;
	unsigned long long val;
}pos;
int sp1=0,front=0,rear=0;
pos buf1[40000],buf2[40000];
int n,m,k;
long long solve(int *D,int n,int m,pos* example,int k,int kind);
int main(){
	scanf("%d%d%d",&n,&m,&k);
	int D[n][m];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%d",&D[i][j]);
			buf1[sp1++]={i,j,2,D[i][j]};
		}
	}
	long long ans=0;
	for(int i=0;i<4 && (front!=rear%40000 || front==0 && rear%40000==0);i++){
		for(int j=0;j<sp1;j++) buf2[rear++]=buf1[j];
		for(;front!=rear%40000;front++) ans+=solve((int*)D,n,m,&buf2[front],k,i);	
		front=0;rear=0;				
	}
	printf("%lld",ans);
}

long long solve(int *D,int n,int m,pos* e,int k,int kind){
	long long ret=0;int w=e->power;
	switch(kind){
		case(0):{//主对角下三角 
			int edge1=e->x-w+1,edge2=e->y+w-1;
			if (edge1>=0 && edge2<=m-1){
				for(int i=0;i<w;i++){
					e->val+=D[(edge1+i)*m+e->y+i];
				}
				if(e->val>=k){
					for(;edge1>=0 && edge2<=m-1;edge1--,edge2++)ret++;
				}
				else {
					e->power++;
					buf2[rear%40000]=*e;
					rear++;
				}
			}
			break;
		}
		case(1):{//主对角上三角 
			int edge1=e->x+w-1,edge2=e->y-w+1;
			if (edge1<=n-1 && edge2>=0){
				for(int i=0;i<w;i++){
					e->val+=D[(e->x+i)*m+edge2+i];
				}
				if(e->val>=k){
					for(;edge1<=n-1 && edge2>=0;edge1++,edge2--)ret++;
				}
				else {
					e->power++;
					buf2[rear%40000]=*e;
					rear++;
				}
			}
			break;
		}
		case(2):{//次对角下三角 
			int edge1=e->x-w+1,edge2=e->y-w+1;
			if (edge1>=0 && edge2>=0){
				for(int i=0;i<w;i++){
					e->val+=D[(edge1+i)*m+e->y-i];
				}
				if(e->val>=k){
					for(;edge1>=0 && edge2>=0;edge1--,edge2--)ret++;
				}
				else {
					e->power++;
					buf2[rear%40000]=*e;
					rear++;
				}
			}
			break;
		}
		case(3):{//次对角上三角 
			int edge1=e->x+w-1,edge2=e->y+w-1;
			if (edge1<=n-1 && edge2<=m-1){
				for(int i=0;i<w;i++){
					e->val+=D[(e->x+i)*m+edge2-i];
				}
				if(e->val>=k){
					for(;edge1<=n-1 && edge2<=m-1;edge1++,edge2++)ret++;
				}
				else {
					e->power++;
					buf2[rear%40000]=*e;
					rear++;
				}
			}
			break;
		}
		default:break;
	}
	return ret;
}