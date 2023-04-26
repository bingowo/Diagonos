#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct N{
	char str[20];
	long long num;
}a[10010];
int count(char* s){
	int l = strlen(s), i, j, ans = 0;
	for(i = 0; i < l; ++i){
		int flag = 1;
		for(j = i - 1; j >= 0; --j){
			if(s[i] == s[j]){
				flag = 0;
				break;
			}
		}
		if(flag)	ans += 1;
	}
	return ans;
}
void solve(struct N *s, int t){
	int flag[257], i, l = strlen(s->str), n = 0;
	long long mult = 1, sum = 0;
	for(i = 0; i <= 256; ++i)	flag[i] = -1;
	flag[s->str[0]] = 1;
	for(i = 0; i < l; ++i){
		if(flag[s->str[i]] == -1){
			flag[s->str[i]] = n;
			if(n == 0) n = 2;
			else	n += 1;
		}
	}
	for(i = l - 1; i >= 0; --i){
		sum += flag[s->str[i]] * mult;
		mult *= t;
	}
	s->num = sum;
}
int cmp(const void *a, const void *b){
	const struct N *pa = a, *pb = b;
	if(pa->num != pb->num){
		if(pa->num > pb->num)	return 1;
		else	return -1; 
	}
	else{
		return strcmp(pa->str, pb->str);
	}
}
int main(){
	int n, i;
	scanf("%d", &n);
	for(i = 0; i < n; ++i){
		scanf("%s", &a[i].str);
		int t = count(a[i].str);
		t = t == 1 ? 2 : t;
		solve(a + i, t);
	}
	qsort(a, n, sizeof(a[0]), cmp);
	for(i = 0; i < n; ++i){
		printf("%s\n", a[i].str);
	}
	return 0;
}