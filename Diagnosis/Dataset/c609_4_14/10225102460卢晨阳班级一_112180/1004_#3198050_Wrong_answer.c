#include<stdio.h>
#include<string.h>
int main()
{
	int a,b;
	char s[20];
	scanf("%d %s %d",&a,s,&b);
	int n=0,m=1;
	for(int i=strlen(s)-1;i>=0;i--){
		if(s[i]>='0'&&s[i]<='9'){
			n=n+(s[i]-'0')*m;
			m=m*a;
		}else if(s[i]>='A'&&s[i]<='F'){
			n=n+(s[i]-'A'+10)*m;
			m=m*a;
		}else if(s[i]>='a'&&s[i]<='f'){
			n=n+(s[i]-'a'+10)*m;
			m=m*a;
		}
	}
	//printf("%d\n",n);
	char p[100]={0};
	int cnt=0;
	while(n!=0){
			if(n/b>9){
				p[cnt]=n%b;
				n=n/b;
				cnt++;
			}else{
				p[cnt]=n%b;
				n=n/b;
				cnt++;
			}	
		}
		for(int j=cnt-1;j>=0;j--){
			if(p[j]<10)
			printf("%d",p[j]);
			else
			printf("%c",55+p[j]);
		}
	return 0;
 } 