#include<stdio.h>
const char In[16] = {"0123456789abcdef"};
int if_d(char *a){
	int i = 0;
	int f = 0;
	while(a[i] != '\0'){
		if(a[i]=='.')f = i;
		i++;
	}
	if(f>0)return i-f-1;
	return 0;//检查到返回0，为int，为double返回小数位
}
void trans(char *a, char*b, int c){//a输入字符串，b输出字符串，c a的小数位
	int i = 0;
	int f = 0;
	int n = 0;//计数n
	int t10 = 1;
	int Ou[64] = {0};
	int k = 0;
	if(a[0]=='-'){
		f = 1;
	}
	while(a[i]!='\0'){
		i++;
	}
	for(int j=i;j>=f;j--){
		if(a[j]=='.')j--;
		n += t10*(a[j] - 48);
		t10 *= 10;
	}
	while(n>0){
		Ou[k++] = n%2;
		n /= 2;
	}
	if(c>0){
		if(f==1)Ou[63] = 1;
		k = 52;
		while(c>0){
			Ou[k++] = c%2;
			c /= 2;
		}
	}//小数
	else{//整数型
		if(f==1){
			for(int j=0;j<32;j++){
				if(Ou[j]==0){
					Ou[j] = 1;
					continue;
				}
				Ou[j] = 0;
			}
			for(int j=0;j<32;j++){
				if(Ou[j]==0){
					Ou[j] = 1;
					break;
				}
				Ou[j] = 0;
			}
		}
	}
	i = 0;
	k = 0;//计数
	t10 = 1;
	int st = 1;
	int sp = 0;
	int m = 0;
	char tep[2] = {'0'};
	for(int j=0;j<64;j++){
		while(sp<2){
			while(st++<=4){
				k += Ou[j++]*t10;
				t10 *= 2;
			}
			tep[sp++] = In[k];
			k = 0;
			t10 = 1;
			st = 1;
		}//sp = 2
		while(sp>0){
			b[m++] = tep[--sp];//sp = 1, 0
		}
	}
}
int main(){
	char Inp[18] = {'\0'};
	char out[16] = {'0'};
	scanf("%s", &Inp);
	int p = if_d(Inp);
	trans(Inp, out, p);
	printf("%s", out);
	return 0;
}