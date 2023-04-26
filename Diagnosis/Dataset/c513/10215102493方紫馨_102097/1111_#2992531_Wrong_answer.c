#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void reserve(char *s){
	char t;
	for(int i=0,j=strlen(s)-1;i<j;i++,j--){
		t = s[i];s[i] = s[j];s[j] = t;
	}
}

void trans(int *x,char* s){
	int a,n,len =strlen(s) ;
	for(int i=5;i<len;i++){
		if(s[i]=='x'){
			if(i-1<5)
				a = 1;
			else if(s[i-1]=='-')
				a = -1;
			else{
				char str_n[10] = {'\0'};
				int cnt = 0;
				while(i-cnt-1>=5){
					str_n[cnt] = s[i-cnt-1];
					if(s[i-cnt-1]=='+'||s[i-cnt-1]=='-'){
						cnt++;break;
					}
					cnt++;
				}
				str_n[cnt] = '\0';
				reserve(str_n);
				a = atoi(str_n);
				
			}
			if(i+1>=len)
				n = 1;
			else{
				if(s[i+1]!='^')
					n = 1;
				else 
					n = s[i+2] - '0';
			}
			x[n] = a;
		}
	}
	char str_n[10]={'\0'};
	int cnt = 0;
	for(int i=len-1;i>=5;i--){
		str_n[cnt] = s[i];
		cnt++;
		if(s[i]=='+'||s[i]=='-')
			break;
		if(s[i]=='x'){
			str_n[0] = '\0'; break;
		}
			
	}
	str_n[cnt] = '\0';
	reserve(str_n);
	x[0] = atoi(str_n);
}
//记录对应的y,x，如果在范围内，标记为1； 
void record(int *x,int n[][41]){
	int y ;
	for(int i=-20;i<=20;i++){
		y = x[3]*i*i*i+x[2]*i*i+x[1]*i+x[0];
		if(y<=20&&y>=-20){
			n[y+20][i+20] = 1;
		}	
	}	
}

int main()
{
	char f[20];
	while(scanf("%s",f)!=EOF){
		//从5开始
		int x[4] = {0}; 
		trans(x,f);
		int n[41][41] = {0};
		record(x,n);
		for(int i=20;i>=-20;i--){
			for(int j=-20;j<=20;j++){
				if(n[i+20][j+20]==1)
					printf("*"); 
				else if(j==0){
					if(i==20)
						printf("^");
					else if(i==0)
						printf("+");
					else
						printf("|");
				}else if(i==0){
					if(j==20)
						printf(">");
					else
						printf("-");
				}else
					printf(".");
				if(j==20)
					printf("\n");
				
			}
		}
	}
	
	
	return 0;	
} 