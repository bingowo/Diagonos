#include <stdio.h>
#include <stdlib.h>
void Quicksort(unsigned long long int a[], int left, int right) {   //快排函数
	int temp;
	int mid = a[(left + right) / 2];            //找基准值
	int i = left;
	int j = right;
//在左侧找一个大于基准值的数，在右侧找一个小于基准数的数，然后交换位置
	while (i <= j) {
		while (a[i] < mid) i++;
		while (a[j] > mid) j--;
		if (i <= j) {
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			i++;
			j--;
		}
	}
	if (i < right) Quicksort(a, i, right);        //递归
	if (j > left) Quicksort(a, left, j);           //递归
}

int main(){
    long long int n;
    scanf("%lld",&n);
    unsigned long long int a[n];
    for(int i=0;i<n;i++){
        scanf("%llu",&a[i]);
    }
    Quicksort(a,0,n-1);
    long long int sum=0;
    for(int i=0;i<n;i+=2){
        sum+=a[i+1]-a[i];
    }
    printf("%lld",sum);


return 0;
}
