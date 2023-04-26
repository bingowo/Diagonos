#include <stdio.h>
int T;
int main(void)
{
	scanf("%d",&T);
	getchar();
	for(int kase=0;kase<T;kase++)
	{
		int num[111] = {0};
		int len = 1;
		char c;
		while(scanf("%c",&c)){
			if(c=='\n') break;
			len++;
			num[len] = c-'0';
		}
		num[len]++;
		for(int i=len;i>=2;i--){
			if(num[i]>=10){
				num[i-1] += num[i]/10;
				num[i] %= 10;
			}
		}
		int pos = len;
		while(pos>=1){
			int find = pos-1;
			while(find>=1 && num[find]==num[pos]) find--;
			if(find==pos-1);
			else{
				int sign = 0;
				for(int i=find+1;i<=pos;i++){
					num[i] = sign;
					sign = (sign^1);
				}
				num[find]++;
				for(int i=find;i>=1;i--){
					num[i-1] += num[i]/10;
					num[i] %= 10;
				}
			}
			pos = find;
		}
		printf("case #%d:\n",kase);
		int st = 0;
		while(st<=len && num[st]==0) st++;
		if(st==len+1) putchar('0');
		else{
			for(int i=st;i<=len;i++) printf("%d",num[i]);
		}
		putchar('\n'); 
	}
	return 0;
 } 