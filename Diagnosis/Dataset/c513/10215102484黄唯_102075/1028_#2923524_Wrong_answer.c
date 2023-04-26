#include <stdio.h>

int cmpD(const int *a,const int *b)
{
	int a1 = *(int *)a;
	int b1 = *(int *)b;
	return a1 < b1 ;
 } 

int cmpA(const int *a,const int *b)
{
	int a1 = *(int *)a;
	int b1 = *(int *)b;
	return a1 > b1 ;
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
		qsort(input,num,sizeof(int),cmpA);
	}else if(c == 'D'){
		qsort(input,num,sizeof(int),cmpD);
	}
	num_del = rmvdup(input, num - 1);
	for(int i = 0 ; i < num; i ++){
		printf("%d%c", input[i], (i == num_del - 1) ? '\n':' ');
	}
	
	
	return 0;
}
