#include <stdio.h>

//获得第一次交集的结果
void intersection1(int* a,int* b,int* c, int A, int B, int*C) 
{
	int i, j, t = 0;
	for (i = 0; i < A; i++) {
		for (j = 0; j < B; j++) {
			if (a[i] == b[j]){
				c[t++] = a[i];
			}
		}
	}
	(*C) = t;
}
//a是输入新的集合 b是交集的集合 A是集合a元素个数 C是更新交集元素个数 
void intersection2(int* a, int* b, int A, int* C) //更新求交集的集合c
{
	int i, j, t = 0;
	int n = *C;
	int c[101]; //交集C 
	for (i = 0; i < A; i++) {
		for (j = 0; j < n; j++) {
			if (a[i] == b[j]) {
				c[t++] = a[i];
			} 
		}
	}
	//更新交集
	for (i = 0; i < t; i++) {
		b[i] = c[i];
	} 
	(*C) = t;
}

//排序
void Sort(int a[], int*c) {
	int i, j, t, p;
	for (i = 0; i < (*c)-1; i++) {
		p = i;
		for (j = i+1; j < (*c); j++) {
			if (a[p] > a[j]) p = j;
		}
		if (p != i) {
			t = a[p];
			a[p] = a[i];
			a[i] = t;
		}
	}
} 

int main() {
	int a[101], b[101], c[101]; //集合A B 交集C 
	int A, B, C = 0; 
	int n, m; 
	int i, j;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &m);
		if (i == 0) {
			A = m; //获得第一个集合元素个数 
			for (j = 0; j < m; j++) {
				scanf("%d", &a[j]);
			}
		}
		else if (i == 1) {
			B = m; //获得第二个集合元素个数 
			for (j = 0; j < m; j++) {
				scanf("%d", &b[j]);
			}
			intersection1(a, b, c, A, B, &C); //获得第一次交集的结果 
		}
		else {
			//通过得到的第一次的交集数组集合，与每次输入的集合数组继续求交集 
			for (j = 0; j < m; j++) {
				scanf("%d", &a[j]);
			} 
			intersection2(a, c, m, &C); //更新求交集的集合c 
		}	
	}
	Sort(c, &C); //从小到大排序 
	for (i = 0; i < C; i++) {
		printf("%d", c[i]);
		if (i+1!=C) {
			putchar(' ');
		}
	}
	return 0;
}
