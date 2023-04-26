#include <stdio.h>
#include <string.h>

/*
0123下标对应RBYG四种颜色。
其中tot和ans数组存储每种颜色的灯应有的总数，
cnt为实际的总数，两者相减即可。
*/

int main(){
	int T,t;
	scanf("%d",&T);
	for (t = 0; t < T; t++){
		char s[101];
		scanf("%s",s);//输入彩灯 
		int len = strlen(s);
		int light4 = len / 4; 
		int cnt[4] = {0,0,0,0},ans[4] = {0,0,0,0};
		char seq[4];
		int i; 
		for (i = 0; i < light4 * 4; i++){
			switch(s[i]){
				case 'R':cnt[0]++;break;
				case 'B':cnt[1]++;break;
				case 'Y':cnt[2]++;break;
				case 'G':cnt[3]++;break;
			}
		}
		//前4k个灯里面所有亮着的个数
		ans[0] = light4 - cnt[0];
		ans[1] = light4 - cnt[1];
		ans[2] = light4 - cnt[2];
		ans[3] = light4 - cnt[3];
		int j = 0;
		while( j + 3 < len){
			if (s[j] != '!'){
				seq[0] = s[j];
			}
			if (s[j + 1] != '!'){
				seq[1] = s[j + 1];
			}
			if (s[j + 2] != '!'){
				seq[2] = s[j + 2];
			}
			if (s[j+3] != '!'){
				seq[3] = s[j + 3];
			}
			j = j + 4;
		}
		for (i = light4 * 4; i < len; i++){
			if (s[i] == '!'){
				switch(seq[i % 4]){
					case 'R': ans[0]++;break;
					case 'B': ans[1]++;break;
					case 'Y': ans[2]++;break;
					case 'G': ans[3]++;break;
				}
			}
		}
		printf("case #%d:\n%d %d %d %d\n",ans[0],ans[1],ans[2],ans[3]);
	}
	return 0; 
} 