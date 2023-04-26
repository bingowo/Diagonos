#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int T,n;
double freq[300];//freq[x] 就表示x字符的频率，大小写统一 
char s[10005];

int cmp(const void* a,const void* b) {
	char x = *(char*)a, y = *(char*)b;
	if(fabs(freq[x] - freq[y]) < 1e-9) {//防止浮点数误差 
		int tmp1 = x, tmp2 = y;
		if(x >= 'a') tmp1 = x - 'a' + 'A';
		if(y >= 'a') tmp2 = y - 'a' + 'A';
		if(tmp1 != tmp2) return tmp1 - tmp2;//不是相同字符的大小写 
		return y - x;//是相同字符的大小写，小写ASCII码更大 
	}
	if(freq[y] > freq[x]) return 1;//比较原则就是按照字符频率的大小（从大到小排序） 
	else return -1;
}

int main() {
	scanf("%d",&T);
	for(int c = 0; c < T; c ++) {
		for(int i = 0; i < 26; i ++)
			scanf("%lf", &freq[i + 'A']), freq[i + 'a'] = freq[i + 'A'];//读入字符的频率 
		scanf("%s", s);
		int l = strlen(s);
		qsort(s,l,sizeof(char), cmp);
		printf("case #%d:\n", c);
		printf("%s\n", s);
	}
	return 0;
}
