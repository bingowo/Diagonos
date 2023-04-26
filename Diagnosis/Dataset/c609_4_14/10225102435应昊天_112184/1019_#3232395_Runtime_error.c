#include<stdio.h>
#include<stdlib.h>
int digits_cnt(int a);
int cmp(const void* a,const void* b);
int main(){
	int d;
	int arr[100000];
	int len = 0;
	while(scanf("%d",&d) != EOF){
		arr[len++] = d;
	}  
	qsort(arr,len,sizeof(int),cmp);
	for(int i = 0;i < len;i++){
		printf("%d",arr[i]);
		if(i != len-1)
			printf("%c",' '); 
	}
	return 0;
}
int digits_cnt(int a){
	int ret = 0;
	do{
		ret++;
	}while(a /= 10);
	return ret;
}
int cmp(const void* a,const void* b){
	int* A = (int *)a;
	int* B = (int *)b;
	if(digits_cnt(*A) == digits_cnt(*B))
		return  *A - *B;
	else
		return  digits_cnt(*B) - digits_cnt(*A);
}