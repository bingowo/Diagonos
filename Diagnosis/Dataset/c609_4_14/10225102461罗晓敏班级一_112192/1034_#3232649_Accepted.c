#include <stdio.h>
#include <string.h>
int islegal(char s[]){
    char *p=s;
    if(strstr(s,"0x")==0){
        return -1;
    }
    while(p=strstr(p,"0x")){
        p+=2;
        if((*p<='f'&&*p>='a')||(*p<='9'&&*p>='0')){
            return 1;
        }
    }
    return -1;
}
int main(){
	char s[100001],*p=s;
	scanf("%s",s);
	unsigned int num;
	if(islegal(s)==-1){
	    printf("-1");
	    return 0;
	}
	while(p=strstr(p,"0x")){
		p+=2;
    	num=0;
    	if(*p>'f')
    	    continue;
    	else
    	while((*p<='f'&&*p>='a')||(*p<='9'&&*p>='0')){
			if(*p<='f'&&*p>='a')num=num*16+*p-'a'+10;
    		else num=num*16+*p-'0';
    		p++;
    	}
    	printf("%u ",num);
    }
	return 0;
} 