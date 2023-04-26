#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct{
	int num;             		//编号 
	int success;
	int fail;
	int point; 
}TEAM;
int cmp(const void* a,const void* b);
int main(){
	int n,m,info;
	int a,b;                   //team
	int flag = 1;
	scanf("%d %d",&n,&m);
	while(flag){
		TEAM* p = (TEAM*)malloc(sizeof(TEAM) * (n+1));
		for(int i = 0;i < n;i++){
			(p+i)->success = 0;
			(p+i)->fail = 0;
			(p+i)->point = 0;
			(p+i)->num = i+1;
		}
		for(int i = 0;i < m;i++){
			scanf("%d %d %d",&a,&b,&info);
			switch(info){
				case 1:
					(p+a-1)->point += 3;
					(p+b-1)->point -= 1;
					(p+a-1)->success++;
					(p+b-1)->fail--;
					break;
				case -1:
					(p+b-1)->point  += 3;
					(p+a-1)->point  -= 1;
					(p+b-1)->success++;
					(p+a-1)->fail--;
					break;
				case 0:
					(p+b-1)->point  ++;
					(p+a-1)->point  ++;
					break;
			}
		}
		qsort(p,n,sizeof(p[0]),cmp);
		for(int i = 0;i < n;i++){
			printf("%d%c",(p+i)->num,(i==n-1 ? '\n':' '));
		}
		free(p);
		n = 0;
		m = 0;
		scanf("%d %d",&n,&m);
		if(n==0 && m==0)
			flag = 0;
	}
	return 0;
}
int cmp(const void* a,const void* b){
	TEAM* A = (TEAM*)a;
	TEAM* B = (TEAM*)b;
	if(A->point == B->point){
		if(A->success == B->success){
			if(A->fail == B->fail){
				return A->num - B->num;
			}else
				return A->fail - B->fail;
		}else
			return B->success - A->success;
	}else
		return B->point - A->point;
}