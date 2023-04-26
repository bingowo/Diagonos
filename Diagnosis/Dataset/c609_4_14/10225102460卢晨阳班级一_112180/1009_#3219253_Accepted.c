#include<stdio.h>
#include<string.h>

int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}

int main()
{
	char str[150]={'\0'};
	int T,s,sum,cnt,q;
	char ch;
	scanf("%d",&T);
	ch=getchar();
	for(int t=0;t<T;t++){ 
		cnt=0;
		gets(str);
		int len=strlen(str);
		sum=8*len*sizeof(char);
		for(int i=0;i<len;i++){ 
			s=(unsigned char)str[i];
			while(s!=0){ 
				if(s%2) cnt++;
				s=s/2;
			}
		}
		q=gcd(cnt,sum);
		cnt=cnt/q;sum=sum/q;
		printf("%d/%d\n",cnt,sum);
	}
	return 0;
}