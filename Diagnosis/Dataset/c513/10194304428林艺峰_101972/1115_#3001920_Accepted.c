#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char str[110];
void swap(char *a, int i, int j){
	char temp = *(a + i);
	*(a + i) = *(a + j);
	*(a + j) = temp;
}
void reverse(char *a, int start, int l){
	int i, j;
	for(i = start, j = l - 1; i < j; ++i, --j){
		swap(a, i, j);
	}
}
int main(){
	int t, i, j;
	scanf("%d", &t);
	for(i = 0; i < t; ++i){
		scanf("%s", &str);
		int l = strlen(str), flag = 0, pos = -1;
		for(j = l - 1; j > 0; --j){
			if(str[j] > str[j-1]){
				pos = j;
				break;
			}
		}
		if(pos == -1){//	不存在更大排列；
			for(j = l - 1; j > 0; --j){
				if(str[j] != '0')	flag = 1;
			}
			if(flag)	reverse(str, 0, l);
			for(j = l; j >= 2; --j){
				str[j] = str[j-1];
			}
			str[1] = '0';
			l += 1;
			str[l] = '\0';
		}
		else{
            int t = pos;
            while(t + 1 < l && str[t + 1] > str[pos - 1]) t++;
            swap(str, pos - 1, t);
            reverse(str, pos, l);
		}
		printf("case #%d:\n%s\n", i, str);
	}
	return 0;
}