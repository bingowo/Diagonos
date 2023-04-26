#include <stdio.h>
#include <string.h>
/*
1.字符串输入 存储
2.每3个一组,转成2进制,存起来
3.剩下的
	1位数-->转4位二进制 
	2位数-->转7位二进制 
4.数字长度二进制 
4.拼起来,输出 
*/


char * itob(int num);

int main(){
	char s[501];
	scanf("%s",s);
	char out[5000];
	char *p = out;
	
	int i;
	int len = strlen(s);
	for(i = 0; i + 2 < len; i = i + 3){
		int num = (s[i] - '0') * 100 + (s[i + 1] - '0') * 10 + (s[ i + 2 ] - '0') * 1;
		strcpy(p, itob(num));
		p += 10;
	}
	if(len - i == 1){
		int num = s[len - 1] - '0';
		strcpy(p,itob(num) + 6);
		p += 4;
	}else if(len - i == 2){
		int num = (s[len - 2] - '0') * 10 + (s[len - 1] - '0');
		strcpy(p,itob(num) + 3);
		p += 7;
	}
	*p = '\0';
	printf("0001%s%s\n", itob(len), out);
}

char * itob(int num){
	static char buf[11];
	int k = 9;
	do{
		buf[k--] = num % 2 + '0';
		num = num / 2;
	} while(num >= 0 && k >= 0);
	return buf;
}