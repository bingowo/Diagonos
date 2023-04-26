#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
long long int Ox2d(char*s){
	long long int sum=0;
	int len1=strlen(s);
	for(int v=0;v<len1;v++){
		if(isdigit(s[v])) sum=sum*16+s[v]-'0';
		if(isalpha(s[v])) sum=sum*16+s[v]-'a'+10;
	}
	return sum;
}
int main(){
	char str[10001];
	char s[10001];
	long long int d[10001];
	scanf("%s",str);
	int len=strlen(str);
	int i=0,j=0,k=0,v=0;
	for(;i<len-2;i++){
		if(str[i]=='0'&&str[i+1]=='x'&&(str[i+2]>='1'&&str[i+2]<='9')||(str[i+2]>='a'&&str[i+2]<='f'))
		{
			memset(s,0,10001*sizeof(char));
			for(j=i+2;(str[j]>='0'&&str[j]<='9')||(str[j]>='a'&&str[j]<='f');j++)
			{ s[k++]=str[j];
			}/*s[k]='\0';*/
		  d[v++]=Ox2d(s);
		    i=j;	}
		else continue;	
	}
	for(int l=0;l<v;l++) printf("%lld ",d[l]);
return 0;
} 