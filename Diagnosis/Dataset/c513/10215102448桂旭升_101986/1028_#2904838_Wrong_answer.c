#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int n[110] = {0};
int cmp1(const void *a, const void *b){
    int i = 0; int *pa = (int *)a, *pb = (int *)b;//printf("%c %c\n", ca, cb);
    //if(*pa == *pb) *pb = 0;
	return *pa-*pb;
}
int cmp2(const void *a, const void *b){
    int i = 0; int *pa = (int *)a, *pb = (int *)b;
    //if(*pa == *pb) *pb = 0;
	return *pb-*pa;
}

int main(){
	int i = 0, num1 = 0, num2 = 0;
	char c;
	scanf("%c", &c);
	while(scanf("%d", &n[i]) != EOF)i++;
	num1 = i; num2 = i;
	qsort(n, i, sizeof(int), cmp1);
	for(i = 0;i < num1;i++){
		if(n[i] == n[i+1]) {
			n[i] = 0;num1--;
		}
	}
	i = 0;//printf("%d\n", num1);
	if(c=='A'){
		qsort(n, num2, sizeof(int), cmp2);
		qsort(n, num1, sizeof(int), cmp1);
	}
	else{
		qsort(n, num2, sizeof(int), cmp2);
		qsort(n, num1, sizeof(int), cmp2);
	}
	for(i = 0; i < num1; i++){
		printf("%d", n[i]);
		if(i != num1 - 1)printf(" ");
	} 
	//if(A[j].t != 1)printf("%d", A[j].real);
}