#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int R(long long int a, long long int b);

int main(){
	char s[5000];
	scanf("%s",s);
	char *p;
	long long int qr,qi,qrr,qii,r,d = 0;
	if(strchr(s,'i') == 0){//只有a
		qr = atoll(s);
		qi = 0;
	}else if (s[0] == 'i')//只有i
	{
		qr = 0;
		qi = 1;
	}else if (strchr(s,'i') && s[0] != 'i'
	&& strchr(s,'+') == 0 && strchr(s,'-') == 0){//纯bi形式
		p = strchr(s,'i');
		*p = '\0';
		qr = 0;
		qi = atoll(s);
	}else if(strchr(s,'i') && s[0] != 'i'){//这里就是复杂的a+bi形式了
		p =strchr(s,'i');
		*p = '\0';
		p = p - 1;//现在p指向末尾
		int j = strlen(s)-1;
		int l;
		l = j;
		for(; (*p != '+') && (*p != '-') && j != -1; j--,p--);
		if((*p == '+') && (j = l)){
			d = 1;
			qi = 1;//往前动一下就是+了说明i前面没有东西,说明qi = 1;
		}else if((*p == '-')&&(j == l)&& (j > 0 )){
			d = 1;
			qi = -1;
		}else if((*p == '-') && (j == l) && (j == 0)){
			qr = 0;
			qi = -1;
		}else if (j == -1){
			qr = 0;
			qi = atoi(s);
		}else if((*p == '-') && (j < l) && (j == 0)){
			qr = 0;
			qi = atoi(s);
		}else if((*p == '-') && (j < l) && (j > 0)){
			d = 1;
			qi = atoll(p);
		}else if ((*p == '+') && (j < l)){
			d = 1;
			qi = atoll(p);
		}else if ((j == -1) && (l > 0)){
			qr = 0;
			qi = atoll(p+1);
		}
		if(d = 1){
			*p = '\0';
			qr = atoll(s);
		}
		
	}
	long long int i[5000] = {0};
	int n = 0;
	do{
		r = R(qi,qr);
		i[n] = r;
		n++;
		qrr = qr;
		qii = qi;
		qr = (r - qrr + qii) / 2;
		qi = (r - qrr - qii) / 2;
	}while((qr != 0) || (qi != 0));
	for(n = n -1; n >= 0; n--){
		printf("%lld",i[n]);
	}
	return 0;
}

int R(long long int a, long long int b){
	if(((a - b) % 2) == 1){
		return 1;
	}else{
		return 0;
	}
}