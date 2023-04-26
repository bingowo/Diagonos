#include<stdio.h>
#include<string.h>
#include<math.h>
#define N 100
#define M 800
char chartobin(char a[])
{
	char s[8];
	for(int j=0;j<8;j++){
		if(a%2) s[7-j]='1';
		else s[7-j]='0';
		a=a>>1;
	}  
}
char* checksix(char s[])
{
	if(strlen(s)%6){
		int n=6-strlen(s)%6;
		char s1[n];
		for(int i=0;i<n;i++){
			s1[i]='0';
		}
		strcat(s,s1);
	}
}
int bintot(char s[])
{
	int n=0;
	for(int i=0;i<6;i++){
		if(s[i]=='1'){
			n+=pow(2,5-i);
		}
	}
	return n;
}
int main()
{
	int t;scanf("%d",&t);
	for(int i=0;i<t;i++){
		char s[N];scanf("%s",&s);
		printf("case #%d:\n",i);
		char t[M],a[8];//t储存整个编码，a储存每个字符的二进制 
		int l=strlen(s);
		for(int j=0;j<l;j++){
			a=chartobin(s[j]);//每个字符转化成二进制 
			strcat(t,a);//链接所有字符串 
		}
		checksix(t);//规整t长度为6的倍数 
		int n=strlen(t)/6,m;//n共几组,m十进制 
		char b[6]; 
		for(int q=0;q<n;q++){
			for(int p=0;p<6;p++){
				b[p]=t[6*q+p]; 
			}
			m=bintot(b);
			if(q==n-1){
				output(m);printf("\n");
			}
			else output(m);
		} 
	}
}