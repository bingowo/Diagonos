#include<stdio.h>
#include<stdlib.h>
int cmp(const void* a,const void* b);
int one_cnt(long long a);
int main(){
	int T;
	scanf("%d",&T);
	long long a[T][10000];
	int b[T];                              //每行元素个数 
	for(int i =0;i < T;i++){
		scanf("%d",&b[i]);
		for(int j = 0;j < b[i];j++){
			scanf("%lld",&a[i][j]);
		}
	}
	for(int i =0;i < T;i++){
		qsort(a[i],b[i],sizeof(long long),cmp);
		printf("case #%d:\n",i);
		for(int j = 0;j < b[i];j++){
			printf("%lld%c",a[i][j],(j == b[i]-1 ? '\n' :' '));
		}
	}
}
int one_cnt(long long n){
	int cnt = 0;
    for (int i = 0;i < 64;++i){
        if(n & 1 == 1)
            cnt++;
        n >>= 1;
    }
    return cnt;
}
int cmp(const void* a,const void* b){
	long long *A = (long long*)a;
	long long *B = (long long*)b;
	if(one_cnt(*A) == one_cnt(*B)){
		if(*A > *B)
			return 1;
		else
			return -1;
	}else
		return one_cnt(*B) - one_cnt(*A);
}