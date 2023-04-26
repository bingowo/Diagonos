#include<stdio.h>
#include<stdlib.h>
int getl(int n){
	int l = 0;
	if(n<0)n = -n;
	while(n>0){
		l++;
		n /= 10;
	}
	return l;
}
int amp(const void *a, const void *b){
	return (*(int*)a-*(int*)b);
}//升序排序，从小到大
int biggest(int *a, int num){
	int b = a[0];
	int bn = 0;
	for(int i=1;i<num;i++){
		if(a[i]>b){
			b = a[i];
			bn = i;
		}
	}
	return bn;
}//返回数组中的最大值的位置，最大值相同，返回最前面的位置
int main(){
	int geint[10] = {0};
	int outp[10] = {0};
	int lon[10] = {0};
	int i = 0;
	while(1){
		scanf("%d", &geint[i++]);
		if(getchar()=='\n')break;
	}
	qsort(geint, i, sizeof(int), amp);
	for(int j=0;j<i;j++){
		lon[j] = getl(geint[j]);
	}//记录geint中对应的位数
	int k = 0;
	int rec = biggest(lon, i);
	while(k<i){
		outp[k] = geint[rec];
		lon[rec] = 0;
		rec = biggest(lon, i);
		k++;
	}
	for(int j=0;j<i;j++){
		printf("%d ", outp[j]);
	}
	return 0;
}