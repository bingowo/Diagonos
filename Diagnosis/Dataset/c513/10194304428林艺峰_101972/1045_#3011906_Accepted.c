#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
struct s{
	char str[110], simple[30];
	int num[110];
}a[100010];
int sign = 0;
int cmp(const void *a, const void *b){
	const struct s *pa = a, *pb = b;
	return pa->num[sign] - pb->num[sign];
}
int main(){
	int n, i, j, ans = 0, flag = 0;
	scanf("%d", &n);
	for(i = 0; i < n; ++i){
		scanf("%s", &a[i].str);
		int l = strlen(a[i].str), len = 0;
		for(j = 1; j < l; ++j){
			if(a[i].str[j] != a[i].str[j-1])
				a[i].simple[len++] = a[i].str[j-1];
		}
		a[i].simple[len++] = a[i].str[l-1];
	}
	for(i = 1; i < n; ++i){
		if(strcmp(a[i].simple, a[i-1].simple)){
			flag = 1;
		}
	}
	if(flag){
		printf("-1");
	}
	else{
		int maxn = 0;
		for(i = 0; i < n; ++i){
			int l = strlen(a[i].str), count = 1, len = 0;
			for(j = 1; j < l; ++j){
				if(a[i].str[j] != a[i].str[j-1]){
					a[i].num[len++] = count;
					count = 1;
				}
				else{
					count += 1;
				}
			}
			a[i].num[len++] = count;
			maxn = len;
		}
		for(i = 0; i < maxn; ++i){
			sign = i;
			qsort(a, n, sizeof(a[0]), cmp);
			for(j = 0; j < n; ++j){
				ans += abs(a[j].num[i] - a[n/2].num[i]);
			}
		}
		printf("%d", ans);
	}
}