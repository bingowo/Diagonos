#include<stdio.h>
#include<ctype.h>
#include<string.h>
int main(){
	char s[50];
	long long int m[26]={0};
	int flag,sum;
	
	while(gets(s)!=NULL&&s[0]!='\0'){
		int len=strlen(s);
	//	printf("00000");
		if(s[0]=='I')//if(!strcmp(s,"IN")) 
		{int i=0;
		sum=0,flag=1;
			while(!isdigit(s[i]))i++;
			if(s[i-1]=='-') flag=-1;
			for(;i<len&&isdigit(s[i]);i++) sum=sum*10+s[i]-'0';
			i=len-1;
			while(s[i]!='X') i--;
			m[s[i-1]-'A']=flag*sum;
			
		}
		//if(!strcmp(s,"ADD"))
		if(s[0]=='A'&&s[1]=='D')
		{
		if(s[len-6]==' ') {
			m[s[len-5]-'A']+=m[s[len-2]-'A'];
		}
    	else if(s[len-6]==','){
		m[s[len-8]-'A']=m[s[len-5]-'A']+m[s[len-2]-'A'];
		
	}
		}
	//f(!strcmp(s,"SUB"))
	if(s[0]=='S')
		{
			if(s[len-6]==' ') {
			m[s[len-5]-'A']-=m[s[len-2]-'A'];
		}
    	else if(s[len-6]==','){
		m[s[len-8]-'A']=m[s[len-5]-'A']-m[s[len-2]-'A'];	
		}
	}
		//if(!strcmp(s,"MUL"))
		if(s[0]=='M'&&s[1]=='U')
		{if(s[len-6]==' ') {
			m[s[len-5]-'A']*=m[s[len-2]-'A'];
		}
    	else if(s[len-6]==','){
		m[s[len-8]-'A']=m[s[len-5]-'A']*m[s[len-2]-'A'];
	}
		}
		//if(!strcmp(s,"DIV"))
		if(s[0]=='D')
		{
			if(s[len-6]==' ') {
			m[s[len-5]-'A']/=m[s[len-2]-'A'];
		}
    	else if(s[len-6]==','){
		m[s[len-8]-'A']=m[s[len-5]-'A']/m[s[len-2]-'A'];
		
		}}
		//
		if(s[0]=='M'&&s[1]=='O'&&s[2]=='V')
		{int c=0;
		int temp=m[s[len-2]-'A'];
		while(s[c]!='X') c++;
		m[s[c-1]-'A']=temp;
		}
		//
		if(s[0]=='X'&&s[1]=='C')
		{int c=4;
		int temp=m[s[len-2]-'A'];
		while(s[c]!='X') c++;
		m[s[len-2]-'A']=m[s[c-1]-'A'];
		}
		//
		if(s[0]=='M'&&s[1]=='O'&&s[2]=='D')
		{
			int mo=0;
		int temp=m[s[len-2]-'A'];
		while(s[mo]!='X') mo++;
		m[s[mo-1]-'A']%=temp;	
		}
		//
		if(s[0]=='A'&&s[1]=='N'&&s[2]=='D')
		{
		if(s[len-6]==' ') {
			m[s[len-5]-'A']&=m[s[len-2]-'A'];
		}
    	else if(s[len-6]==','){
		m[s[len-8]-'A']=m[s[len-5]-'A']&m[s[len-2]-'A'];
	}
		}
		//
		if(s[0]=='O'&&s[1]=='R'){
			if(s[len-6]==' ') {
			m[s[len-5]-'A']|=m[s[len-2]-'A'];
		}
    	else if(s[len-6]==','){
		m[s[len-8]-'A']=m[s[len-5]-'A']|m[s[len-2]-'A'];	
		}}
		//
		if(s[0]=='X'&&s[1]=='O'&&s[2]=='R'){
			if(s[len-6]==' ') {
			m[s[len-5]-'A']^=m[s[len-2]-'A'];
		}
    	else if(s[len-6]==','){
		m[s[len-8]-'A']=m[s[len-5]-'A']^m[s[len-2]-'A'];	
		}
	}
		
		//if(!strcmp(s,"OUT"))
		if(s[0]=='O'&&s[1]=='U')
		{
		printf("%lld\n",m[s[len-2]-'A']);
		}	
	}
}