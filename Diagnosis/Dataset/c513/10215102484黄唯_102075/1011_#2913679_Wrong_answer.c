#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main(){
	char s[100000],t[100000];
	scanf("%s",s);
	int k = 0;
	for(int i = 2;i < strlen(s); i ++){
		int n;
		n = s[i] >= 'A'? s[i]-'A'+10 : s[i] - '0';
		unsigned int flag = 0x8;
		while(flag){
			if(n & flag == '1') t[k++] = '1';
			else t[k++] = '0';
			flag = flag >> 1;
			
		}
	}
	long long int qr = 0,qi = 0;
	long long int a,b;
	for(int i = 0;i < k;i ++){
		int j = t[i] - '0';
		a = -qr - qi + j;
		b = qr - qi;
		qr = a;
		qi = b;
	}
	 if(qi==0)
        printf("%lld",a);
    else
    {
        if(qr!=0)
        {
            printf("%lld",qr);
            if(qi>0)printf("+");
        }

        if(qi==1)printf("i\n");
        else if(qi==-1)printf("-i\n");
        else printf("%lldi\n",qi);

	
	
	
	}
	return 0;
}
  