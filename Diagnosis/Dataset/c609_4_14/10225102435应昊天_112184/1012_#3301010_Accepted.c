#include<stdio.h>
#include<string.h>
int main(){
	int T;
	scanf("%d",&T);
	char s[51];
	for(int i = 0;i < T;i++){
		int base[150] = {0};
		base[0] = 1,base[1] = 2,base[2] = 5;
		int ans[150] = {0};                                     //避免末尾0输出 
		int temp[150] = {0};
		int cnt = 3;                                             //base位数 
		scanf("%s",s);
		for(int j = 2;s[j] != '\0';j++){                         //跳过0. 
			int remainder = 0;
			for(int k = cnt - 1;k >= 0;k--){                		 //与base位数相同  
				temp[k] = (s[j] - '0') * base[k] + remainder;
				remainder = temp[k] / 10;                 		 //进位 
				temp[k] %= 10;		
			}
			remainder = 0;
			for(int k = cnt - 1;k >= 0;k--){
				ans[k] += temp[k] + remainder;
				remainder = ans[k] / 10;
				ans[k] %= 10;
			}
			int sum = 0;
			for(int l = 0;l < cnt+3;l++){            			//最多增加三位 
				sum = sum * 10 + base[l];
				base[l] =  sum / 8;
				sum %= 8;
				}
			cnt+=3;
		}
		printf("case #%d:\n",i);
		printf("0.");
		for(int m = cnt - 1;ans[m] == 0;m--){
			cnt--;
		}
		for(int m = 0;m < cnt;m++){
			printf("%d",ans[m]);
		}
		printf("\n");
	}
	return 0;
}