#include<stdio.h>
#include<string.h>
int main(){
	char a[501];
	char b[501];
	int ans[501];
	while(scanf("%s %s",a,b)){
		int len_a = strlen(a);
		int len_b = strlen(b);
		int sign = 0;      
		if(len_a < len_b){
			sign = 1;
		}
		else if(len_a == len_b){
			for(int i = 0;i < len_a;i++){
				if(a[i] < b[i]){
					sign = 1;
					break;
				}
			}
		} 
		int i,j;
		int up = 0;                                               //借位 
		for(i = len_a-1,j = len_b-1;i >= 0 && j >= 0;i--,j--){
			if(!sign){
				ans[i] = a[i] - b[j] + up;
				if(ans[i] < 0){
					ans[i] += 10;
					up = -1;	
				}else
					up = 0;  
			} 
			else{
				ans[j] = b[j] - a[i] + up;
				if(ans[j] < 0){
					ans[j] += 10;
					up = -1;	
				}else
					up = 0;
			}
			//printf("%d ",ans[i]); 
		}
		for(int cnt = i;cnt >= 0;cnt--){               //位数不一致 
			ans[cnt] = a[cnt] - '0' + up;
			if(ans[cnt] < 0){
				ans[cnt] += 10;
				up = -1;
			}else
				up = 0;
			//printf("%d ",ans[cnt]);
		}
		for(int cnt = j;cnt >= 0;cnt--){
			ans[cnt] = b[cnt] - '0' + up;
			if(ans[cnt] < 0){
				ans[cnt] += 10;
				up = -1;
			}else
				up = 0;
		}
		if(sign)
			putchar('-');
		int flag = 0;
		for(int k = 0;k < (sign ? len_b:len_a);k++){
			if(ans[k] != 0 || flag){
				printf("%d",ans[k]);
				flag = 1;
			}
		}
		printf("\n");
		memset(ans,0,sizeof(ans));
	}
	
	return 0;
}