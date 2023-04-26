#include <stdio.h>
#include <string.h>
int main(){
	char s[100001],*p=s;
	scanf("%s",s);
	unsigned int num;
	if(p=strstr(p,"0x"))
		while(p=strstr(p,"0x")){
			if((*p<='f'&&*p>='a')||(*p<='9'&&*p>='0')){
				p+=2;
	    		num=0;
	    		while((*p<='f'&&*p>='a')||(*p<='9'&&*p>='0')){
					if(*p<='f'&&*p>='a')num=num*16+*p-'a'+10;
	    			else num=num*16+*p-'0';
	    			p++;
	    		}
	    		printf("%u ",num);
			}
	    }
	else{
		printf("-1");
	}
	return 0;
} 