#include<stdio.h>
#include<string.h>
typedef struct equation{
	int x;
	int n;
};
int trans_char_num (char []);
equation trans(char s[]){
	char num_char[10],x_char[5];
	for(int i=0;i<strlen(s);i++){
		
		if(s[i]=='x'){
			if(i+2<strlen(s)&&s[i+1]=='^'){
				x_char[0] = s[i+2];i+=2;                         
				if(i+1<strlen(s)&&(s[i+1]!='+'||s[i+1]!='-')){
					x_char[1] = s[i+3];i++;
				}
			}
			if(i-1<0||s[i-1]=='+'||s[i-1]=='-')
				num_char = '1';
			equation.n = trans
			continue;
		}
		num_char=s[i];
	}
}
int main()
{
	char x1[100];
	char x2[100];
	while(scanf("%s%s",x1,x2)!=EOF){
		
	}
	
	return 0;
}