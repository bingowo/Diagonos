#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int main(){
	char s[100000];
	char t[100000];
	int k = 0;
	scanf("%s",s);
	int i;
	for (i = 2; i < strlen(s); i++){
		int n;
		if (s[i] > 'A'){
			n = i - 'A' + 10;
		}else{
			n = i - '0';
		}//获得了每一位上的数字
		int flag = 8;
		while(flag != 0){
			if (flag & n != 0){
				t[k] = '1';
			}else{
				t[k] = '0';
			}
			k++;
		}
	}//把16进制每一位上的数字变成4位二进制存进字符串数组t里
	long long int qr = 0;
	long long int qi = 0;
	long long int r;
	long long int a,b;
	for (i = 0; i < strlen(t); i++){
		r = t[i] - '0';
        a = r - qr - qi;
        b = qr-qi;
        qr = a;
        qi = b;
	}
	if(qi==0){
    	printf("%lld",a);
	}else{
        if(qr!=0)
        {
            printf("%lld",qr);
            if(qi>0)printf("+");
        }

        if(qi==1){
        	printf("i\n");	
		}
        else if(qi==-1){
        	printf("-i\n");	
		}
        else{
        	printf("%lldi\n",qi);	
		} 
    }
}