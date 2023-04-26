#include<stdio.h>
int ret_shang(int n){
	int ret = 0;
	int tep = -1;
	if(n<0){
	while(tep!=0||tep!=1){
		ret++;
		tep = n+ret*2;
	}
	return ret;
	}
	else{
		tep = n+ret*2;
		while(tep!=0||tep!=1){
			ret--;
			tep = n+ret*2;
		}
		return ret;
	}
}

int main(){
	int n = 0;
	int i = 0;
	int tep = 0;
	char ret[100] = {'0'};
	scanf("%d", &n);
	while(n!=0){
		tep = n;
		n = ret_shang(n);
		ret[i++] = 48+tep+2*n;
	}
	for(int j = i;j>=0;j--){
		printf("%c", ret[j]);
	}
	return 0;
}
/*#include<string.h>
void mo2(char *a, char *c, int i){
	int get = 0;
	int tep = 0;
	int carry = -1;
	if(a[0] == '-'&&strlen(a)==2){//处理负数
		get = 48-a[1];
		while(carry!=1||carry!=0){
			tep++;
			carry = tep*2+get;
		}
		a[0] = tep+48;
		c[i++] = carry+48;
	}//ret为正数
	else if(a[0]!='-'&&strlen(a)==1){
		get = a[0] - 48;
		carry = get+tep*2;
		while(carry!=1||carry!=0){
			tep--;
			carry = get+tep*2;
		}
		if(tep==0){a[0] = '0';a[1] = '0';}
		else{
			a[0] = '-';
			a[1] = 48-tep;
		}
		c[i++] = carry+48;		
	}
	else if(a[0] == '-'){
		
	}
	else{
		
	}
}
int main(){
	char a[110] = {'0'};//输入大整数
	char c[110] = {'0'};//存储答案
	int i = 0;
	scanf("%s", &a);
	
	return 0;
	
}*/