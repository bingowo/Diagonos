#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int f(char* ans, char a) {	//判断a是否在ans数组里面 
	char *p = ans;
	int state = 0;
	while (*p != '\0') {
		if (*p++ == a) {
			state = 1;
			break;
		}
	}
	return state;
}

int g(char* ans, char a) {	//返回a的索引 
	char *p = ans;
	while (*p != '\0') {
		if (*p == a) {
			return p - ans;
			
		}
		p++;
	}
}

int main() {
	int T;
	scanf("%d",&T) ;
	int m = 0;
	while(m<T) {
		char ans[100] = {'\0'};
		char s[100];
		scanf("%s",s);
		int l = strlen(s);
		
		ans[0] = s[0];
		for (int i = 1, n = 1; i < l; i++) {	//如果s中的元素是ans中没有的就添加到ans中 
			if (!f(ans, s[i])) {
				ans[n] = s[i];
				n++;
			}
		}

		long long sum = 0;
		long long temp = 1;		//两个long long 要注意 
		int weight = strlen(ans);
		l--;
		
		if (strlen(ans) > 1) {
			int t = ans[0];		//把开头两个元素的索引换一下 
			ans[0] = ans[1];
			ans[1] = t;		
			while (l >= 0) {
				sum += g(ans, s[l]) * temp;
				temp *= weight;
				l--;
			}			
		} else {	//如果都是同一个元素的话，如“111111”或“aaaaaaa" 
			sum = (int)pow(2, l+1) - 1;
		}

		printf("case #%d:\n%ld\n",m,sum);
//		for (int i = 0; i < weight; i++) {
//			printf("%c",ans[i]);
//		}
		m++;

	}
    return 0;
}
