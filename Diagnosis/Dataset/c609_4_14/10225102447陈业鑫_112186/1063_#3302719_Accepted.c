#include<stdio.h>
int main(){
	int num = 0;
	int getint[10] = {0};
	scanf("%d", &num);
	for(int i=0;i<num;i++){
		scanf("%d", &getint[i]);
	}
	long long int tree[50] = {1, 2, 4, 8};//1--1;2--1 1, 2;3--1 1 1,1 2, 2 1, 3;
	//前四项都为前项和+本身
	int max = 3;
	for(int i=0;i<num;i++){
		printf("case #%d:\n", i);
		int temp = getint[i]-1;
		if(temp<=max){
			printf("%lld\n", tree[temp]);
		}
		else{
			max = temp;
			for(int j=4;j<=max;j++){
				tree[j] = tree[j-1]+tree[j-2]+tree[j-3]+tree[j-4];
			}
			printf("%lld\n", tree[temp]);
		}
	}
	return 0;
}