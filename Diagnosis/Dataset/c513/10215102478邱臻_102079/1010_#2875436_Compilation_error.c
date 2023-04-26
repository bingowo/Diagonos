#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int zhishu(int r){
	int i,result=1;
	for(i=1;i<=r;i++){
		result*=10;
	}
	return result;
}
void bin(char s[10],int n,int all){
	int l,k=0;
	while(n!=0){
		l=n%2;n=n/2;
		s[k]=l+'0';
		k++;
			}
	while(k!=all-1){
		s[k]='0';
		k++;
	} 
}
int main() {
	int i=0;
	char num[500],s[10];
	char result[10000]={'0','0','0','1'};
	scanf("%s",num);
	while(num[i]!='\0'){
		i++;
	}  //字符串的位数 
	for(x=)
	for(j=0;j<i;j++){
		k=0;l=2;a=0;
		while(k!=3 || i-j>=3){
			a+=(num[j]-'0')*zhishu(l);
			k++;l--;j++;
		}   //化为三位数	
		if(i-j==2 && k!=3){
			a=(num[j]-'0')*10+(num[j+1]-0);
		}  //两位数 
		else if(i-j==1 && k!=3){
			a=(num[j]-'0');
		}  //一位数 
		
	}
	return 0;
}