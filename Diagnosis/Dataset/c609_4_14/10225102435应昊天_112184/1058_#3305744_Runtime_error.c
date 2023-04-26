#include<stdio.h>
#include<string.h>
typedef struct{
	int cnt;
	int num[102];
}BIGINT;
void ADD1 (BIGINT* p);
void DIV2 (BIGINT* p);
int main(){
	BIGINT p;
	char s[101];
	scanf("%s",s);
	int len = strlen(s);
	int sign = 1;
	p.cnt = 0;
	for(int i = len - 1;i >= 1;i--){         //0为个位 
		p.num[p.cnt++] = s[i] - '0';       //字符串数值转换 
	}
	if(s[0] == '-')
		sign = -1;
	else
		p.num[p.cnt++] = s[0] - '0';
	int bin[401] = {0};
	int cnt = 0;
	while(p.cnt > 0){
		bin[cnt++] = p.num[0] % 2;
		if(sign == -1 && bin[cnt-1]){          
			/*if(p.cnt == 0){
				p.cnt++;
				p.num[0] = 1;
			}
			else*/
				ADD1(&p);	
		} 
		DIV2(&p);
		sign *= -1;
	}
	for(int i = cnt - 1;i >= 0;i--){
		printf("%d",bin[i]);
	}
	printf("\n");
	return 0;
} 
void ADD1 (BIGINT* p){
	p->num[0]++;
	int carry = 0;
	for(int i = 0;i < p->cnt;i++){
		p->num[i] += carry;
		carry = p->num[i] / 10;
		p->num[i] %= 10;
	}
	if(carry)
		p->num[p->cnt++] = carry;                  //进位改变位数 
}
void DIV2 (BIGINT* p){
	int carry = 0;
	if(p->num[p->cnt-1] == 1){              	  //首位可能为0 
		p->cnt--;                             //改变cnt,for loop仍从cnt-1开始 
		carry = 1;
	}
	for(int i = p->cnt-1;i >= 0;i--){
		int tot = 10 * carry + p->num[i];
		carry = tot % 2;
		p->num[i] = tot / 2; 
	}
}