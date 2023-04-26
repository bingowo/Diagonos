#include<stdio.h>
#include<string.h>
int GDC(int a,int b){
	
	if(a%b==0)
		return b;
	return GDC(b,a%b);
}
int onecnt(unsigned char ch){
	int a=ch;
	int d=1,cnt=0;
	for(int i=0;i<8;i++){
		if(a&d){
			cnt++;
		}
		d=d<<1;
	}
	return cnt;
}
int main()
{
	int n;
	scanf("%d",&n);
	getchar();
	
	for(int i=0;i<n;i++){
		unsigned char s[121],ch;
		int a=0,b=0;
		gets(s);
		//printf("%s",s);
		for(int j=0;j<strlen(s);j++){
			a+=onecnt(s[j]);
			b+=8;
		}
		int t;
		t=GDC(b,a);
		b/=t,a/=t;
		printf("%d/%d\n",a,b);
		
	}
	return 0;
}