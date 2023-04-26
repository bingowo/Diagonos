#include<stdio.h>
#include<stdlib.h>
int a_cmp(const void* a,const void* b);
int d_cmp(const void* a,const void* b);
int main(){
	char c;
	int flag = 0;
	scanf("%c",&c);
	if(c == 'D')
		flag = 1;
	int d; 
	int arr1[100];
	int len = 0;
	while(scanf("%d",&d) != EOF){
		arr1[len++] = d;
	}  
	if(flag)
		qsort(arr1,len,sizeof(int),d_cmp);
	else
		qsort(arr1,len,sizeof(int),a_cmp);
	int arr2[100];
	arr2[0] = arr1[0];
	int a = arr1[0];
	int cnt = 1;
	for(int i = 1;i < len;i++){
		if(arr1[i] != a)
			arr2[cnt++] = arr1[i];
		else
			continue;
		if(i != len - 1)
			a = arr1[i];
	}
	for(int i = 0;i < cnt;i++){
		printf("%d",arr2[i]);
		if(i != cnt-1)
			printf("%c",' '); 
	}
	return 0;
} 
int a_cmp(const void* a,const void* b){
	return *(int*)a - *(int*)b;
}

int d_cmp(const void* a,const void* b){
	return *(int*)b - *(int*)a;
}