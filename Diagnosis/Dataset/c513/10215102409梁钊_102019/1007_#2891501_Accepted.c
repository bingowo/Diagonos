#include<stdio.h>
#include<string.h>
int main()
{
	int T;
	scanf("%d",&T);
	for(int i=0;i!=T;i++){
		char s[100]={'0'};
		char* p = s;
		long long int n;
		scanf("%lld",&n);
		while(n){
			*(p++)=(char)((1 & n)+'0');
			n>>=1;
		}
		for(int j=0;j!=strlen(s)/2;j++){
			char tmp=s[j];
			s[j]=s[strlen(s)-1-j];
			s[strlen(s)-1-j]=tmp;
		}
		int longest=0;
		p = s ;
		while(p-s<strlen(s)){
			int lon=1;
			int flag=0;
			while(*p==*(++p)) flag=1;
			p--;
			while(*p!=*(++p)&& (p-s<strlen(s))) lon++;
			if(lon>longest) longest=lon;
		}
		printf("case #%d:\n%d\n",i,longest);
		
	}
	
} 