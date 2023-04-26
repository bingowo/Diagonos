#include<stdio.h>
#include<ctype.h>
#include<string.h>
int main(){
	char s[20];
	int m[26],flag=1,sum;
	while(gets(s)!=NULL){
		int len=strlen(s);
		if(!strcmp(s,"IN")) 
		{int i=0;
			while(!isdigit(s[i]))i++;
			if(s[i-1]=='-') flag=-1;
			for(;i<len&&isdigit(s[i]);i++) sum=sum*10+s[i]-'0';
			i=0;
			while(s[i]!='X') i++;
			m[s[i-1]-'A']=flag*sum;
		}
		if(!strcmp(s,"ADD"))
		{int j=0;
		int temp=m[s[len-2]-'A'];
		while(s[j]!='X') j++;
		m[s[j-1]-'A']+=temp;
		}
		if(!strcmp(s,"SUB"))
		{int ji=0;
		int temp=m[s[len-2]-'A'];
		while(s[ji]!='X') ji++;
		m[s[ji-1]-'A']-=temp;
		}
		if(!strcmp(s,"ADD"))
		{int c=0;
		int temp=m[s[len-2]-'A'];
		while(s[c]!='X') c++;
		m[s[c-1]-'A']*=temp;
		}
		if(!strcmp(s,"DIV")){
			int ch=0;
		int temp=m[s[len-2]-'A'];
		while(s[ch]!='X') ch++;
		m[s[ch-1]-'A']/=temp;
		}
		if(!strcmp(s,"OUT"))
		{int v=0;
		printf("%d",m[s[len-2]-'A']);
		}	
	}
}