#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 500
int a[N] = {0};
int b[N] = {0};
int d[2][1001] = {0};

int cmp(const void *a, const void *b){
	int pa = *(int*)a, pb = *(int*)b;
	if(d[1][pa] != 0 && d[1][pb] != 0)return d[0][pa] - d[0][pb];
	if(d[1][pa] != 0 && d[1][pb] == 0)return -1;
	if(d[1][pa] == 0 && d[1][pb] != 0)return 1;
	if(d[1][pa] == 0 && d[1][pb] == 0)return pa - pb;
}

int main(){ 
	int i = 0, n, m;
	scanf("%d", &n);
	for(i = 0; i < n; i++){
		scanf("%d", &a[i]);
		d[0][a[i]] = i;
		d[1][a[i]]++;
	}
	scanf("%d", &m);
	for(i = 0; i < m; i++){
		scanf("%d", &b[i]);
	}
	qsort(b, m, sizeof(int), cmp);
	for(i = 0; i < m; i++){
		printf("%d", b[i]);
		if(i != m-1)printf(" ");
	}	
	return 0;
}