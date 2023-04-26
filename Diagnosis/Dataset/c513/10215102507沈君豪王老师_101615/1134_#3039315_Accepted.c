#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct{
	char id[12];
	int a, c, m, e;
}Info;

int cmp_a(const void *a, const void *b)
{
	Info *pa = (Info *)a;
	Info *pb = (Info *)b;
	if(pa->a != pb->a){
		return pb->a - pa->a;
	}else{
		return strcmp(pa->id, pb->id);
	}
}

int cmp_c(const void *a, const void *b)
{
	Info *pa = (Info *)a;
	Info *pb = (Info *)b;
	if(pa->c != pb->c){
		return pb->c - pa->c;
	}else{
		return strcmp(pa->id, pb->id);
	}
}

int cmp_m(const void *a, const void *b)
{
	Info *pa = (Info *)a;
	Info *pb = (Info *)b;
	if(pa->m != pb->m){
		return pb->m - pa->m;
	}else{
		return strcmp(pa->id, pb->id);
	}
}

int cmp_e(const void *a, const void *b)
{
	Info *pa = (Info *)a;
	Info *pb = (Info *)b;
	if(pa->e != pb->e){
		return pb->e - pa->e;
	}else{
		return strcmp(pa->id, pb->id);
	}
}

int main(void)
{
	int t;
	scanf("%d", &t);
	for(int i = 0 ; i < t; i ++){
		int n;
		scanf("%d", &n);
		Info in[n];
		for(int j = 0 ; j < n ; j ++){
			scanf("%s %d %d %d", in[j].id, &in[j].c, &in[j].m, &in[j].e);
			in[j].a = round((in[j].c + in[j].m + in[j].e) / 3.0);
		}
		int max = 0;
		printf("case #%d:\n", i);
		printf("A:\n");
		qsort(in, n, sizeof(Info), cmp_a);
		max = in[0].a;
		for(int j = 0 ; in[j].a == max; j ++){
			printf("%s\n", in[j].id);
		}
		printf("C:\n");
		qsort(in, n, sizeof(Info), cmp_c);
		max = in[0].c;
		for(int j = 0 ; in[j].c == max; j ++){
			printf("%s\n", in[j].id);
		}
		printf("M:\n");
		qsort(in, n, sizeof(Info), cmp_m);
		max = in[0].m;
		for(int j = 0 ; in[j].m == max; j ++){
			printf("%s\n", in[j].id);
		}
		printf("E:\n");
		qsort(in, n, sizeof(Info), cmp_e);
		max = in[0].e;
		for(int j = 0 ; in[j].e == max; j ++){
			printf("%s\n", in[j].id);
		}			
	}
}