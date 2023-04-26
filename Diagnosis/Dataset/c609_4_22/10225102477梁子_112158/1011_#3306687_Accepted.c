#include<stdio.h>
#include<stdlib.h>
#include<string.h>
long long Gcd(long long a,long long b){
	if(b%a==0)return a;
	else return Gcd(b,a%b);
}
int main()
{
	char s[31];
	scanf("%s",s);
	long long A=0,B=0,C=1;
	int len=strlen(s);
	int ret=0,temp;
	int i=0;
	for(;i<len;i++){
		if(s[i]=='.'){
			ret=i;
			break;
		}//没有小数点的情况，以及小数点前面部分的和 
		if(s[i]=='1')temp=1;
		else if(s[i]=='2')temp=-1;
		else temp=0;
		A=A*3+temp; 
	}
//有小数点的情况
    if(ret!=0){
    	int j=ret+1;
    	for(;j<len;j++){
    		if(s[j]=='1')temp=1;
		else if(s[j]=='2')temp=-1;
		else temp=0;
		B=B*3+temp; 
		C=C*3; 
		}
		temp=Gcd(abs(B),C);//abs取B的绝对值，最终化为最简形式 
		if(A==0){
			printf("%lld %lld",B/temp,C/temp);
		}else{
			if(A>0&&B>0||A<0&&B<0){
				printf("%lld %lld %lld",A,B/temp,C/temp);
			}else{
				if(A>0){
					A-=1;
					B=B+C;
					temp=Gcd(B,C);
					if(A!=0)printf("%lld %lld %lld",A,B/temp,C/temp);
					else printf("%lld %lld",B/temp,C/temp);
				}else{
					A+=1;
					B=C-B;
					temp=Gcd(B,C);
					if(A!=0)printf("%lld %lld %lld",A,B/temp,C/temp);
					else printf("%lld %lld",B/temp,C/temp);
				}	
			}
		} 
    }
    else printf("%lld",A);
	return 0;
}