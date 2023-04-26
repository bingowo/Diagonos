#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int Gcd(int a,int b)
{
	if(b==0)return a;//b可能为0 
	else return(b,a%b);
}
void solve(){
	char s[122];
	fgets(s,122,stdin);//fgets输入函数，第一位首地址，第二位输入最大长度，第三位来源文件，stdin输入，stdout输出；
	int l=strlen(s)-1;
	int i=0;
	int fz=0,fm;
	fm=8*l;
	for(;i<l;i++)
	{
		unsigned char c=s[i];
		while(c>0){
			if(c&1)fz++;
			c>>=1;
		}
	 }
	 int g; 
	 g=Gcd(fm,fz);
	 printf("%d/%d\n",fz/g,fm/g);
}
int main()
{
	int t;
	scanf("%d",&t);
	int i=0;
	for(;i<t;i++){
		solve();
	}
	return 0;
}
	