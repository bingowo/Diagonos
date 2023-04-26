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
		int d;
		if (s[i] >= 'A'){
			d = s[i] - 'A' + 10;
		}else{
			d = s[i] - '0';
		}//获得了每一位上的数字
		unsigned int flag = 8;
		while (flag != 0){
			if((d & flag) != 0){
				t[k]='1';
			}//&位运算 全1取1 有0取0 
            else{
            	t[k]='0';
			}
			k++;
            flag=flag>>1;
		}
	}//把16进制每一位上的数字变成4位二进制存进字符串数组t里
	long long int qr = 0;
	long long int qi = 0;
	long long int a,b;
	for (i = 0; i < k; i++){
		int r;
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

