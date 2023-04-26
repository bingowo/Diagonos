#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int myscanf(char* buf){
	char s[150];int sp=0;
	char c;
	while((c=getchar())!='\n'){
		if(c==' ')break;
		else s[sp++]=c;
	}
	s[sp]=0;strcpy(buf,s);
	if(c==' ')return 1;
	return -1;
}
void lower(char*s){
	for(int i=0;s[i]!=0;i++){
		s[i]=tolower(s[i]);
	}
}
int cmp(char*buf){
	lower(buf);int tag=0;
		if(strcmp(buf,"the")==0);
		else if(strcmp(buf,"a")==0);
		else if(strcmp(buf,"an")==0);
		else if(strcmp(buf,"for")==0);
		else if(strcmp(buf,"of")==0);
		else if(strcmp(buf,"and")==0);
		else tag++;
		return tag;
}
int main()
{
	long long t;
	scanf("%lld",&t);getchar();
	for(int index=0;index<t;index++){
		char buf[100];int ans=0;
		while(myscanf(buf)!=-1){
			ans+=cmp(buf);
		}
		ans+=cmp(buf);
		printf("case: #%d:\n%d\n",index,ans);
	} 
	return 0;
}