#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int num1=10,num2,i,num,len,temp1,temp2,temp3;
	char a[3000];
	char s[3000];
	scanf("%s",s);
	printf("0001");
	len=strlen(s);
	while(len>=3){
	for(i=num1;i<=num1+strlen(s)-2;i+=3){
		temp1=s[i]-'0';
		temp2=s[i+1]-'0';
		temp3=s[i+2]-'0';
		num=100*temp1+10*temp2+temp3;
		len-=3;
		int cnt=1;
		while(num>0){
			a[num1+10-cnt]=num%2;
			num/=2;
			cnt++;}
		while(cnt<=10){
			a[num1-cnt+10]=0;
			cnt++;}
		num1+=10;
		}
}
	if(len==2){
		i=num1+1;
		temp1=s[i]-'0';
		temp2=s[i+1]-'0';
		num=10*temp1+temp2;
		int cnt=1;
		while(num>0){
			a[num1+7-cnt]=num%2;
			num/=2;
			cnt++;}
		while(cnt<=7){
			a[num1-cnt+7]=0;
			cnt++;}	
		}	
	if(len==1){
		i=num1+1;
		temp1=s[i]-'0';
		num=temp1;
		int cnt=1;
		while(num>0){
			a[num1+4-cnt]=num%2;
			num/=2;
			cnt++;}
		while(cnt<=4){
			a[num1-cnt+4]=0;
			cnt++;}	
		}	
	int cnt1=0;
	int len1=strlen(s);
	while(len1>0){
	a[10-cnt1]=len1%2;
	len1=len1/2;
	cnt1++;
	while(cnt1<=10){
		a[10-cnt1]=0;
		cnt1++;
	}
	}	
	printf("%s",a);		
	
	
	return 0;
}