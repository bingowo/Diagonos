#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int T;
int main() {
	char s[305], res[805], tmp[805], ans[805];
	scanf("%d", &T);
	for(int c = 0; c < T; c ++) {
		for(int i = 0; i < 800; i ++) res[i] = ans[i] = 0;//ans记录答案
		res[1] = 1, res[2] = 2, res[3] = 5;//0.125,用来当作基数
		int mov = 3;//用来记录小数位
		scanf("%s", s);
		for(int i = 2; s[i] != '\0'; i ++) {//从小数点后第一位开始

			int up = 0;//记录进位
			for(int j = mov; j; j --) {
				tmp[j] = res[j] * (s[i] - '0') + up;
				up = tmp[j] / 10, tmp[j] %= 10;
			}//tmp用于储存单位八进制的结果

			up = 0;
			for(int j = mov; j; j --) {
				ans[j] = tmp[j] + ans[j] + up;
				up = ans[j] / 10, ans[j] %= 10;
			}//高进度加法，大家应该很熟悉了

			int tot = 0;
			for(int j = 1; j <= mov + 3; j ++) {//除法 看！！
				tot = tot * 10, tot += res[j];//列式除法
				res[j] = tot / 8;
				tot %= 8;//余数
			}//相当于res/=8
			mov += 3;//最多增加三位非零小数位 改变基底和位数 每次都加3
		}
		while(ans[mov] == 0) mov --;//去掉低位的0
		printf("case #%d:\n0.",c);
		for(int i=1; i <= mov; i ++) printf("%d", ans[i]);
		puts("");
	}
	return 0;
}