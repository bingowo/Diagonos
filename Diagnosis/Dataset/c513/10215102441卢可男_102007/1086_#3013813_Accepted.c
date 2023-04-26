#include <stdio.h>
#include <string.h>
#define LEN 1000

void stof(char s[], int f[], int delta)
{
	char *p = NULL;
	int idx = LEN - 1;
	for(p = s; *p ; p ++);
	delta = delta > 0 ? delta : 0 ;
	for(int i = 0 ; i < delta; i ++){
		f[idx --] = 0;
	}
	while(1){
		p --;
		if(*p != '.'){
			f[idx --] = *p - '0';
		}
		if(p == s){
			break;
		}
	}
}

void sub(int a[], int b[])
{
	for(int i = LEN - 1; i; i --){
		a[i] -= b[i];
		for(int k = i; a[k] < 0; k --){
			a[k] += 10;
			a[k - 1] -= 1;
		}
	}
}

void fround(int f[], int pidx, int n)
{
	int idx, cnt = 0;
	for(idx = 0 ; f[idx] == 0 && idx < pidx/*这个是为了不过度移位*/; idx ++);
	for(; idx < LEN; idx ++){
		if(idx >= pidx){
			cnt ++;
		}
		if(cnt == n && idx != LEN - 1){
			if(f[idx + 1] >= 5){
				f[idx] += 1;
				for(int k = idx; f[k] >= 10; k --){
					f[k] %= 10;
					f[k - 1] += 1;
				}
			}
			break;
		}		
	}
}

int cmp(int a[], int b[])
{	
	int ret = 0;
	for(int i = 0 ; i < LEN ; i ++){
		if(a[i] > b[i]){
			ret = 1;
			break;
		}else if(a[i] < b[i]){
			ret = -1;
			break;
		}
	}
	
	return ret;
}

int main(void)
{
	char a[LEN], b[LEN];
	int n;
	scanf("%s %s %d", a, b, &n);
	int fa[LEN] = {0}, pa = 0, fb[LEN] = {0}, pb;
	int f[LEN] = {0};
	pa = strstr(a, ".") ? strlen(a) - (strstr(a, ".") - a) - 1 : 0;
	pb = strstr(b, ".") ? strlen(b) - (strstr(b, ".") - b) - 1 : 0;
	stof(a, fa, pb - pa), stof(b, fb, pa - pb);
	int idx, pidx = LEN - ((pa > pb) ? pa : pb), cnt = 0, sgn = cmp(fa, fb);
	if(sgn != 0){
		if(sgn == 1){
			sub(fa, fb);
			memmove(f, fa, sizeof(fa));
		}else if(sgn == -1){
			sub(fb, fa);
			memmove(f, fb, sizeof(fb));
		}
		fround(f, pidx, n);
		for(idx = 0 ; f[idx] == 0 && idx < pidx ; idx ++);
		if(idx == pidx){
			printf("0");
		}else if(sgn == -1){
			printf("-");
		}
		for(; idx < LEN && cnt != n; idx ++){
			if(idx > pidx){
				cnt ++;
			}else if(idx == pidx){
				printf(".");
				cnt ++;
			}
			printf("%d", f[idx]);
		}
		if(pa == 0 && pb == 0){
			printf(".");
		}
		for(; cnt < n; cnt ++){
			printf("0");
		}		
	}else{
		printf("0.%0*d", n, 0);
	}
	
	return 0;
}
