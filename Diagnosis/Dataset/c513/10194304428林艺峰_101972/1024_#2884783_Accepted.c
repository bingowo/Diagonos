#include <stdio.h>
#include <stdlib.h>
struct student{
	char num[12];
	long long score;
}p[510];
int a[20];
int cmp(const void *a, const void *b){
	const struct student *pa = a, *pb = b;
	if((*pa).score == (*pb).score)	return strcmp((*pa).num, (*pb).num);
	if((*pa).score > (*pb).score)	return -1;
	return 1;
}
int main(){
	int t, i, j, k, n, m, s, x, ans = 0;
	long long g;
	scanf("%d", &t);
	for(i = 0; i < t; ++i){
		ans = 0;
		scanf("%d%d%lld", &n, &m, &g);
		for(j = 0; j < n; ++j)	p[j].score = 0;
		for(j = 0; j < m; ++j)	scanf("%d", &a[j]);
		for(j = 0; j < n; ++j){
			scanf("%s", &p[j].num);
			scanf("%d", &s);
			for(k = 0; k < s; ++k){
				scanf("%d", &x);
				p[j].score += a[x-1]; 
			}
		}
		for(j = 0; j < n; ++j)	if(p[j].score >= g)	ans += 1;
		qsort(p, n, sizeof(p[0]), cmp);
		printf("case #%d:\n%d\n", i, ans);
		for(j = 0; j < n; ++j){
			if(p[j].score >= g)	printf("%s %lld\n", p[j].num, p[j].score);
		}
	}
	return 0;
}