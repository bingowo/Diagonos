#include <stdio.h>
#include <string.h>
#define LEN 1000	//开的有点大，但是……实话说，如果不是他给的数字太大（远超过500）也不想开这么大 

void stof(char s[], int f[], int delta/*数组偏移量，<=0则不偏离*/)
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

void add(int f[], int a[], int b[])
{
	for(int i = LEN - 1; i; i --){
		f[i] = f[i] + a[i] + b[i];
		for(int k = i; f[k] >= 10; k --){
			f[k] %= 10;
			f[k - 1] += 1;
		}
	}
}

void fround(int f[], int pidx, int n)
{
	int idx, cnt = 0;
	for(idx = 0 ; f[idx] == 0 ; idx ++);
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

int main(void)
{
	char a[LEN], b[LEN];
	int n;
	scanf("%s %s %d", a, b, &n);
	int fa[LEN] = {0}, pa = 0, fb[LEN] = {0}, pb;
	int f[LEN] = {0};
	//因为strlen()找不到时返回NULL，计算会出现问题，因此这里要用三目运算符 
	pa = strstr(a, ".") ? strlen(a) - (strstr(a, ".") - a) - 1 : 0;
	pb = strstr(b, ".") ? strlen(b) - (strstr(b, ".") - b) - 1 : 0;
	stof(a, fa, pb - pa), stof(b, fb, pa - pb);
	add(f, fa, fb);
	int idx, pidx = LEN - ((pa > pb) ? pa : pb), cnt = 0;
	fround(f, pidx, n);
	for(idx = 0 ; f[idx] == 0 ; idx ++);
	if(idx == pidx){
		printf("0");
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
	//如果小数点全部都在最后或者没有 
	if(pa == 0 && pb == 0){
		printf(".");
	}
	for(; cnt < n; cnt ++){
		printf("0");
	}
	
	return 0;
}