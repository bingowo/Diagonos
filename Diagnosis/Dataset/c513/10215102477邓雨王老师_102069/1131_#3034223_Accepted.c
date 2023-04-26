#include<stdio.h>
#include<string.h>
void convert(char s[]){            //用来转化负数（即把字符串中'1'换成'2'，'2'换成'1' 
	int length=strlen(s);
	int j;
	for(j=0;j<strlen(s);j++){
		if(s[j]=='1') s[j]='2';
		else if(s[j]=='2') s[j]='1';
	}
}
void itob(long long A,long long B,char s[100],int k) //k用来表示小数点的位置 
{
int i=0,j,d;
char c;
long long a=A;
if(a<0) a=-a;    //先暂时把负数也当做整数来处理 
else if(a==0) printf("0"); 
if(A%B==0){
	long long temp=a/B;
	while(temp>0){
		if(temp%3==2){
			s[i]='2';
			temp=(temp+1)/3;
			i++;
		}
		else if(temp%3==1){
			s[i]='1';
			temp=(temp-1)/3;
			i++;
		}
		else{
			s[i]='0';
			temp=temp/3;
			i++;
		}
	}
	s[i]='\0';
}
else {
	long long b=B;
	while(a!=0||b!=0){
		if(i==k){
			s[i]='.';
			i++;
		}
		else if((a%3==2)&&(i!=k)){
			s[i]='2';
			a=(a+1)/3;
			i++;
			b=b/3;
		}
		else if(a==0&&b!=0&&i!=k){
			s[i]='0';
			i++;
			b=b/3;
		}
		else if((a%3==1)&&(i!=k)){
			s[i]='1';
			a=(a-1)/3;
			i++;
			b=b/3;
		}
		else if((a%3==0)&&(i!=k)){
			s[i]='0';
			a=a/3;
			i++;
			b=b/3;
		}
	}
	s[i]='\0';
}
for(i=0,j=strlen(s)-1;i<j;i++,j--) //反转
c=s[i],s[i]=s[j],s[j]=c;
if(A<0) convert(s);
if(A%B!=0){
	int length=strlen(s);   //用来清掉字符串末尾多余的0 
	for(i=strlen(s)-1;s[i]=='0';i--){
		s[i]='\0';
	}
}
}
int calculate(long long B){
	int k=0;
	while(B>=3){
		k++;
		B=B/3;
	}
	return k; 
} 
int main(){
    long long A,B;
    char s[1000];
    scanf("%lld %lld",&A,&B);
    int k=calculate(B);
    itob(A,B,s,k);
    printf("%s",s);
}