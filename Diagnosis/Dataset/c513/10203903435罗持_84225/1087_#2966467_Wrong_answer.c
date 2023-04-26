#include <stdio.h>
int T;
int main(void)
{
	scanf("%d",&T);
	getchar();
	for(int kase=0;kase<T;kase++)
	{
		int num[111] = {0};
		int len = 0;
		char c;
		while(scanf("%c",&c)){
			if(c=='\n') break;
			len++;
			num[len] = c-'0';
		}
		num[len]++;
		for(int i=len;i>=1;i--){
			if(num[i]>=10){
				num[i-1] += num[i]/10;
				num[i] %= 10;
			}
		}
		int pos = len;
		int flag = 0;
		while(pos>=0){
			int find = pos-1;
			while(find>=0 && num[find]==num[pos]) find--;
			if(find==pos-1);
			else{
				int sign = 0;
				for(int i=find+1;i<=pos;i++){
					num[i] = sign;
					sign = (sign^1);
				}
				if(find!=0){
					num[find]++;
					for(int i=find;i>=1;i--){
						num[i-1] += num[i]/10;
						num[i] %= 10;
					}
				}else{
					flag = 1;
				}
			}
			pos = find;
		}
		printf("case #%d:\n",kase);
		if(flag==1) printf("%d",flag);
		for(int i=1;i<=len;i++) printf("%d",num[i]);
		putchar('\n'); 
	}
	return 0;
 } 