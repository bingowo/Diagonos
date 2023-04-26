#include<stdio.h>
#include<string.h>
int pd(char s[],int i){ //i代表位置 
    if(strlen(s)==1) return 1;
	if(i==0&&strlen(s)!=1){
		if(s[i]==s[i+1]) return 1;
		else return 2;
	}
	else if(i==strlen(s)-1&&i!=0){  //i在末尾，且字符串长度不为1 
		if(s[i]==s[i-1]) return 1;
		else return 2; 
	}
	else{
		int count=0;
		if(s[i]!=s[i-1]) count++;
		if(s[i]!=s[i+1]) count++;
		if(s[i-1]!=s[i+1]) count++;
		if(count==0) count++;
		return count;
	}
}
int main(){
	char s[1001];
	scanf("%s",s);
	int i;
	long long sum=1;
	for(i=0;i<strlen(s);i++){
		sum=(sum*(pd(s,i)%100000007)%100000007);
	}
	printf("%lld",sum);
} 
 