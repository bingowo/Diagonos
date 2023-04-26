#include<stdio.h>
long long int N_ten(int a,char n[]){
	int p=1,len=strlen(n);
	long long int sum=0;
	for(int i=len-1;i>=0;i--){
		if(isdigit(n[i])){
			sum=sum+(n[i]-'0')*p;
		}
		else{
			switch(n[i]){
				case 'a':sum=sum+10*p;break;
				case 'A':sum=sum+10*p;break;
				case 'b':sum=sum+11*p;break;
				case 'B':sum=sum+11*p;break;
				case 'c':sum=sum+12*p;break;
				case 'C':sum=sum+12*p;break;
				case 'd':sum=sum+13*p;break;
				case 'D':sum=sum+13*p;break;
				case 'e':sum=sum+14*p;break;
				case 'E':sum=sum+14*p;break;
				case 'f':sum=sum+15*p;break;
				case 'F':sum=sum+15*p;break;
			}
		}
		p*=a;
	}
	return sum;
}
void change(int a,char n[],int b){
	int lenn=strlen(n);
	if(n[0]=='0'&&lenn==1){//特判0 
		printf("0\n") ;
		return;
	}
	long long int tn;
	if(a!=10)//如果不是10进制，那么a进制转b进制 
		tn=N_ten(a,n);
	else//如果就是10进制，那么直接赋给tn 
		sscanf(n,"%lld",&tn);
		
		
	if(b!=10){//如果不是10进制，那么10进制转b进制 
		char str[100];
		int len=0;
		while(tn){
			if(tn%b<10){
					str[len++]=tn%b+'0';
				}
			else{
				switch(tn%b)
				{
					case 10: 	str[len++]='A';break;
					case 11: 	str[len++]='B';break;
					case 12: 	str[len++]='C';break;
					case 13: 	str[len++]='D';break;
					case 14: 	str[len++]='E';break;
					case 15: 	str[len++]='F';break;
				}
			}
		tn/=b;
		}
		for(int i=len-1;i>=0;i--)
			printf("%c",str[i]);
		printf("\n");
		return;
	}
	else{//如果就是10进制，那么直接输出 
		printf("%lld\n",tn);
		return;
	}
	
}
int main(){
	char str[100];
	int a,b;
	
	while(scanf("%d %s %d",&a,str,&b)!=EOF){
		if(a!=b) 
			change(a,str,b);
		else{
			for(int i=0;i<strlen(str);i++)
			printf("%c",str[i]);
		printf("\n");
		}
	}
	return 0;
} 
