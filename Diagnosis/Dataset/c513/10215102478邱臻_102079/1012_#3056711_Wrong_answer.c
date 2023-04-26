#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	char s[100];
	long long int num[100000]={}; 
	long long int a=0,b=0,sign=1,z,i,qr,qi,r;
	scanf("%s",s);
	//只有a
	if(strchr(s,'i')==NULL){
		if(s[0]=='-')sign=-1;
		else sign=1;
		for(i=0;i<strlen(s);i++){
			if(isdigit(s[i]))a=a*10+s[i]-'0';
		}
		a=a*sign;b=0;
	} 
	//既有a也有b
	else if(strchr(s,'+') || (strchr(s,'-')!=NULL && strchr(s,'-')!=strrchr(s,'-'))  || (strchr(s,'-')!=NULL && strchr(s,'-')==strrchr(s,'-') && s[0]!='-' && s[0]!='i')){
		if(s[0]=='-')sign=-1;
		else {sign=1;a=s[0]-'0';}
		z=1;
		while(s[z]!='-' && s[z]!='+'){
			if(isdigit(s[z]))a=a*10+s[z]-'0';
			z++;
		}
		a=a*sign;
	    //计算a的数值
	    if(s[z]=='-')sign=-1;
	    else sign=1;
	    z++;b=1;
	    while(s[z]!='i')b=b*10+s[z++]-'0';
	    b=b*sign;
	    //计算b的数值
	} 
	//只有b 
	else {
		if(s[0]=='-')sign=-1;
		else sign=1;
		z=0;b=1;
		while(s[z]!='i'){
			if(isdigit(s[z]))b=b*10+s[z++]-'0';
		}
		b=b*sign;a=0;
	}
	qr=1;qi=1;r=0;z=0;
	while(qr!=0 || qi!=0){
		if((a%2==0 && b%2==0) || (a%2!=0 && b%2!=0))r=0;
		else r=1;
		qi=(r-a-b)/2;qr=(r-a+b)/2;
	    a=qr;b=qi;
	    num[z++]=r;
	}
	for(i=z-1;i>=0;i--)printf("%lld",num[i]);
	return 0;
}