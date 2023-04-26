#include<stdio.h>
#include<string.h>
long long int hex(char *a,char *pend){
	a+=2;
	long long int ret=0;
	for(;a!=pend;a++){
		if(!((*a>='0'&&*a<='9')||(*a>='a'&&*a<='f')))		
			break;
		if(*a>='a')
			*a = *a -'a'+10;
		else
			*a -= '0';
		ret = ret*16 + *a;
	}
	return ret;
}
int main()
{
	char s[100001];
	scanf("%s",s);
	char* p = s;
	char* pend = s+strlen(s);
	int isout = 0;
	while(p!=pend){
		if(*p=='0'&&*(p+1)=='x'){
			printf("%lld ",hex(p,pend));
			isout = 1;	
		}
		p++;
	}
	if(isout==0){
		printf("-1");
	}
	return 0;
}