#include<stdio.h>
#include<string.h>
int onecnt(char ch){
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
		char s[120];
		int a=0,b=0;
		gets(s);
		//printf("%s",s);
		for(int j=0;j<strlen(s);j++){
			a+=onecnt(s[j]);
			b+=8;
		}
		
		for(int k=2;k<=a;k++){
			if(a%k==0&&b%k==0){
				a/=k,b/=k;
			}
		}
		printf("%d/%d",a,b);
		
	}
	return 0;
}