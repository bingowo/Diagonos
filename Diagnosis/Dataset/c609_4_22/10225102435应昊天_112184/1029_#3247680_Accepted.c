#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct{
	int num;
	int flag;
	int cnt;
}elem;
int cmp(const void* a,const void* b);
int main(){
	int n,m;
	scanf("%d",&m);
	int A[m+1];
	for(int i = 0;i < m;i++){
		scanf("%d",&A[i]);
	}
	scanf("%d",&n);
	elem* p = (elem*)malloc(sizeof(elem) * (n+1));
	for(int j = 0;j < n;j++){
		scanf("%d",&(p+j)->num);
		(p+j)->flag = 0;
		(p+j)->cnt = 0;
		for(int k = 0;k < m;k++){
			if((p+j)->num == A[k]){
				(p+j)->flag = 1;
				(p+j)->cnt = k;
				break;
			}
		}
	}
	qsort(p,n,sizeof(elem),cmp);
	for(int j = 0;j < n;j++){
		printf("%d ",(p+j)->num);
	}
	free(p);
	return 0;
} 
int cmp(const void* a,const void* b){
	elem*aa = (elem*)a;
	elem*bb = (elem*)b;
	if(aa->flag == bb->flag){
		if(aa->flag)
			return aa->cnt - bb->cnt;
		else
			return aa->num - bb->num; 
	}else
		return bb->flag - aa->flag;
}