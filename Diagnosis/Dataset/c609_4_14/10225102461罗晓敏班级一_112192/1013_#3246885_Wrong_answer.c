#include <stdio.h>
#include <math.h>
#include <string.h>
int num2[200];int q;
void f3(int a,int i){
	q=(i+1)*4-1;
	while(a/2){
		num2[q]=a%2;
		q--;
		a/=2;
	}
	num2[q]=a%2;
	if(q%4!=0){
		while(q%4!=0){
			q--;
			num2[q]=0;
		}
	}
}
void f(char a[]){
	int i,b;
	for(i=0;a[i];i++){
		if(a[i]>='0'&&a[i]<='9'){
			b=a[i]-'0';
		}else{
			b=tolower(a[i])+10-'a';
		}
		f3(b,i);
	}
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
	char num1[50];scanf("%s",num1);
	f(num1+2);
	int c,i;
	if(num2[q+3]==1) a=1;
	for(i=q+2;i>=0;i--){
		int j=q+3-i;
		if(num2[i]==1){
			c=f2(j);
			if(j%4==1){
				a-=c;
				b+=c;
			}else if(j%4==2){
				b-=2*c;
			}else if(j%4==3){
				b+=2*c;
				a+=2*c;
			}else if(j%4==0){
				a-=4*c;
			}
		}
	}
	if(a==0){                               //b=0,1,-1要单独考虑 
		if(b==0)printf("0");
		else if(b==1)printf("i");
		else if(b==-1)printf("-i");
		else printf("%lldi",b);
	}else{
		if(b==0)printf("%lld",a);
		else if(b==1)printf("%lld+i",a);
		else if(b==-1)printf("%lld-i",a);
		else if(b>(long long)1)printf("%lld+%lldi",a,b);
		else printf("%lld-%lldi",a,-b);
	}
} 