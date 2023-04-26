#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
void rve(char s[]){	
	char t ;
	for(int i=0,j=strlen(s)-1;i<j;i++,j--){
		t = s[i];s[i] = s[j];s[j] = t;
	}
}
void trans(int* x,const char* s){
	int len = strlen(s);
	int* px = x,a,n;
	char a_ch[10]={'0'};
	for(int i=0;i<len;i++){
		if(s[i]=='x'){
			if(i-1<0)
				a = 1;
			else if(s[i-1]=='-')
				a = -1;
			else if(s[i-1]=='+')
				a = 1;
			else if(i-2<0)
				a = s[i-1] - '0';
			else if(i-2>=0){
				int cnt = 0;
				while(i-cnt>0){
					a_ch[cnt] = s[i-1-cnt];					
					if(s[i-1-cnt]=='+'||s[i-1-cnt]=='-'){
						cnt++;break;
					}						
					cnt++;
				}
				a_ch[cnt] = '\0';
				rve(a_ch);
				a = atoi(a_ch);
			}
			if(i+1>=len||s[i+1]!='^'){
				n = 1;
			}
				
			else{
				i+=2;
				int cnt = 0;
				while(i+cnt<len&&isdigit(s[i+cnt])){
					a_ch[cnt] = s[i+cnt];
					cnt++;
				}
				a_ch[cnt] = '\0';
				n = atoi(a_ch);
			}
			x[n] = a;
		}		
	}
	int j=0,i;
	for(i = len-1;i>=0;i--){
		a_ch[j++] = s[i];
		if(s[i]=='-'||s[i]=='+')
			j++;break;
	}
	if(i==-1)
		return ;
	a_ch[j] = '\0';
	rve(a_ch);
	x[0] = atoi(a_ch);
}


int main()
{
	char s1[101],s2[101];	
	while(scanf("%s%s",s1,s2)!=EOF){
		int x1[50]={0},x2[50]={0},ret[50]={0};
		trans(x1,s1);
		trans(x2,s2);
		for(int i=0;i<50;i++){
			for(int k=0;k<=i;k++){
				ret[i] += x1[k]*x2[i-k];
			}
		}
		for(int i=49;i>=0;i--){
			if(ret[i]!=0)
				printf("%d ",ret[i]);
		}
		printf("\b\n");
	}
	
	return 0;
 } 