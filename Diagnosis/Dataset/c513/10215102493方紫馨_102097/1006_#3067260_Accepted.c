#include<stdio.h>
#include<string.h>
int main()
{
	int T;
	scanf("%d",&T); 
	for(int k=0;k<T;k++){
		char s[20];
		scanf("%s",s);
		int len=strlen(s);
		int ret=s[0]-'0',d;
		for(int i=1;i<len;i++){
			if(s[i]=='1')
				d=1;
			else if(s[i]=='-')
				d=-1;
			else if(s[i]=='0')
				d=0;
			ret=ret*3+d;
		}
		printf("case #%d:\n",k);
		printf("%d\n",ret);
	}
	
	return 0;
 } 