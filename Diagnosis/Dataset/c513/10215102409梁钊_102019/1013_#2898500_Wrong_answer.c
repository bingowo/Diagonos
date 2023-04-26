#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
	char s[31]={'0'};
	scanf("%s",&s);	
	int i=0;
	long integer=0;int r=3;

	///计算整数部分///
	while(s[i]!='.' && i!=strlen(s)){
		int a=1;
		if(s[i]=='0') a=0;
		if(s[i]=='2') a=-1;
		if(i==strlen(s)-1 || s[i+1]=='.'){
			integer += a*1 ;
			i++;
			break ;
		}
		integer = ( integer + a ) * r ;
		i++;
	}
	///判断是否有小数部分///
	if(i<strlen(s)-1){
		i++;
		///计算小数部分///
		int den = pow(3,strlen(s)-i) , mol = 0 ;
		int h=strlen(s)-i-1;
		while(i!=strlen(s)){
			int a=1;
			if(s[i]=='0') a=0;
			if(s[i]=='2') a=-1;
			mol += a * pow(3,h) ;
			h--;i++;
		}
		///分数是否影响整数///
		int flag=0;
		if(mol<=0) flag=1;
		if(integer>0) {
			if(flag==1){
				integer-=1;
				printf("%ld %d %d",integer,den+mol,den);
			}
			else printf("%ld %d %d",integer,mol,den);
		}
		else if(integer<0) {
			if(flag==0){
				integer+=1;
				printf("%ld %d %d",integer,den-mol,den);
			}
			else printf("%ld %d %d",integer,-1*mol,den);
		}
		else{
			printf("%d %d",mol,den);
		}
	}
	else printf("%ld",integer);
}

