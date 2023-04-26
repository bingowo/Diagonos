#include<stdio.h>
#include<string.h>
char* convert(long long a,char s[]){  //把一个十进制数转换为字符数组形式的二进制 
	int i=0;
	while(a>0){
		s[i]=a%2+48;
		a/=2;
		i++;
	}
	return s;
}
long long cal(int n,int m){  //m表示1的数量 
	long long count=0;
	long long sum=1<<n;
	long long i;
	char s2[32];
	for(i=1;i<=m;i++){
		s2[i-1]='1';
	} 
	for(i=1;i<sum;i++){
		char s[32];
		if(strstr(convert(i,s),s2)) count++;
	}
	return count;
}
int main(){
	int n,m;
	while(scanf("%d",&n)!=-1&&scanf("%d",&m)!=-1){
		printf("%lld\n",cal(n,m));
	}
}