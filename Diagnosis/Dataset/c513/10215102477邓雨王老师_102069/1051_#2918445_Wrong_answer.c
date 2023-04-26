#include<stdio.h>
#include<string.h>
const int base[64] = {
	'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 
	'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 
	'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 
	'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f', 
	'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 
	'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 
	'w', 'x', 'y', 'z', '0', '1', '2', '3',
	'4', '5', '6', '7', '8', '9', '+', '/',
};
int main(){
	int chance;
	scanf("%d",&chance);
	int i;
	for(i=0;i<chance;i++){
		char s[101];
		scanf("%s",&s);
		char t[201];
		int j;
		long long sum=0;
		for(j=0;j<strlen(s);j++){
			sum=sum*64+s[j];          //sum代表未补位时的ascii码大小 
		}
		if(8*strlen(s)%6==0) sum=sum;
		else if(8*strlen(s)%6==2) sum=sum*16;
		else sum=sum*4;
		int p=0;
		while(sum>0){
			t[p]=base[sum%64];
			p++;
			sum=sum/64;
		}
		int x;
		char c;
		for(x=0,j=strlen(t)-1;x<j;x++,j--) //反转
c=t[x],t[x]=t[j],t[j]=c;
        while(p<=3){
        	t[p]='=';
        	p++;
		}
		t[p]='\0';
		printf("case #%d:\n",i);
		printf("%s\n",t);
	}
} 