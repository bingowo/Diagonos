#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int A[1001] = {-1};//A中元素各不相同，进行映射，输入的m个整数分别对应下标，存的值是输入的相对顺序
static int cmpB(const void* a, const void* b){
	int x = *((int*)a);
	int y = *((int*)b);
	return A[x] - A[y];
}
static int cmpC(const void* a, const void* b){
	return *((int*)a) - *((int*)b);
}
int main(){
	int m, n, temp, b=0 ,c=0;
	scanf("%d", &m);
	
	for(int i = 0; i<m; i++){
		scanf("%d", &temp);
		A[temp] = i+1;
	}
	scanf("%d", &n);
	int B[n];//B中存放A中有的
	int C[n];//C中存放A中没得
	for(int i = 0; i<n; i++){
		scanf("%d", &temp);
		if(A[temp]>0){
			B[b++] = temp;
		}
		else{
			C[c++] = temp;
		}
	}
	qsort(B, b, sizeof(int), cmpB);//按相对位置映射
	qsort(C, c, sizeof(int), cmpC);//升序
	for(int i = 0; i<b; i++){
		printf("%d ", B[i]);
	}
	for(int i = 0; i<c; i++){
		printf("%d ", C[i]);
	}
	return 0;
}