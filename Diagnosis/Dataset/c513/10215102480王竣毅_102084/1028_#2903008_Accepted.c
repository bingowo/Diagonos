
#include <stdio.h>

void swap(int a[], int i, int j)
{
	int temp;
	temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}

void qsort_up(int a[], int left, int right)
{
	int i, last;
	if(left >= right){
		return ;
	}
	swap(a, left, (left + right) / 2);
	last = left;
	for(i = left + 1; i <= right; i++){
		if(a[i] < a[left]){
			swap(a, i, ++last);
		}
	}
	swap(a, left, last);
	qsort_up(a, left, last - 1);
	qsort_up(a, last + 1, right);
}

void qsort_down(int a[], int left, int right)
{
	int i, last;
	if(left >= right){
		return ;
	}
	swap(a, left, (left + right) / 2);
	last = left;
	for(i = left + 1; i <= right; i++){
		if(a[i] > a[left]){
			swap(a, i, ++last);
		}
	}
	swap(a, left, last);
	qsort_down(a, left, last - 1);
	qsort_down(a, last + 1, right);
}

int rmvdup(int a[], int n)
{
	int ret;
	if(n == 0){
		ret = 0;
	}else{
		int *a1, *a2;
		a1 = a;
		a2 = a1 + 1;
		ret = 1;
		for(int i = 1; i < n; i ++){
			if(*a1 != *a2){
				a1 += 1;
				*a1 = *a2;
				ret ++;
			}
			a2 += 1;
		}
	}
	
	return ret;
}

int main(void)
{
	char c;
	int input[1001], num = 0, num_del;
	scanf("%c", &c);
	while(scanf("%d", &input[num++]) != EOF);
	if(c == 'A'){
		qsort_up(input, 0, num - 2);
	}else if(c == 'D'){
		qsort_down(input, 0, num - 2);
	}
	num_del = rmvdup(input, num - 1);
	for(int i = 0 ; i < num_del; i ++){
		printf("%d%c", input[i], (i == num_del - 1) ? '\n':' ');
	}
	
	
	return 0;
}
