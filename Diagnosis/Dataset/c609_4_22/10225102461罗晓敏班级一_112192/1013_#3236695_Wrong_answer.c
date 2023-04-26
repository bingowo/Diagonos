#include <stdio.h>
#include <math.h>
#include <string.h>
long long int f(char a[]){
	long long int ret=0;
	int i;
	for(i=0;a[i];i++){
		if(a[i]>='0'&&a[i]<='9')ret=ret*16+a[i]-'0';
		else ret=ret*16+tolower(a[i])+10-'a';
	}
	return ret;
}
long long int f2(int j){
	int i;
	long long int ret=1;
	for(i=0;i<(j-1)/4;i++){
		ret*=(-4);
	}
	return ret;
}
int main(){
	long long int a=0,b=0;
	char num1[50];
	scanf("%s",num1);
	long long int temp=f(num1+2),c,i;
	if(temp&1) a=1;
	for(i=1;i<31;i++){
		if(temp>>i&1){
			c=f2(i);
			if(i%4==1){
				a-=c;
				b+=c;
			}else if(i%4==2){
				b-=2*c;
			}else if(i%4==3){
				b+=2*c;
				a+=2*c;
			}else if(i%4==0){
				a-=4*c;
			}
		}
	}
	if(a==0){                               //b=0,1,-1要单独考虑 
		if(b==0)printf("0");
		else if(b==1)printf("i");
		else if(b==-1)printf("-i");
		else printf("%di",b);
	}else{
		if(b==0)printf("%d",a);
		else if(b==1)printf("%d+i",a);
		else if(b==-1)printf("%d-i",a);
		else printf("%d%c%di",a,b>0?'+':'-',abs(b));
	}
} 