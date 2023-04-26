#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char *month[] = {"pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu", "uayet"};
struct Maya{
	int y, m, d;
}a[10010];
int cmp(const void *a, const void *b){
	const struct Maya *pa = a, *pb = b;
	if((*pa).y != (*pb).y)	return (*pa).y - (*pb).y;
	if((*pa).m != (*pb).m)	return (*pa).m - (*pb).m;
	return (*pa).d - (*pb).d;
}
int main(){
	int t, i, j, k, n, num_day, num_month;
	char str_day[20], str_month[20];
	scanf("%d", &t);
	for(i = 0; i < t; ++i){
		scanf("%d", &n);
		for(j = 0; j < n; ++j){
			num_day = 0;
			scanf("%s%s%d", &str_day, &str_month, &a[j].y);
			for(k = 0; k < strlen(str_day); ++k){
				if(str_day[k] != '.'){
					num_day = num_day * 10 + str_day[k] - '0';
				}
			}
			a[j].d = num_day;
			for(k = 0; k < 19; ++k){
				if(strcmp(month[k], str_month) == 0)
					a[j].m = k;
			}
		}
		qsort(a, n, sizeof(a[0]), cmp);
		printf("case #%d:\n", i);
		for(j = 0; j < n; ++j){
			printf("%d. %s %d\n", a[j].d, month[a[j].m], a[j].y);
		}
	}
	return 0;
}