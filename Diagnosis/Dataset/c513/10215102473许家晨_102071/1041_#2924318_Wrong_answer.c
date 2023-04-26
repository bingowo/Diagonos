#include<string.h>
#include<stdio.h>
//
int getlenth(char s[]){
	char* ps=s;
	int len=1;
	int max=1; 
	while(*ps){
		if(*ps==*(ps+1)){
			len=1;
			ps++;
		}
		else{
			len++;
			ps++;
		}
		if(len>max){
			max=len;
		}
	}
	return max;
}
int main(){
	char s[51]={'\0'};
	scanf("%s",s);
	int c=getlenth(s);
	printf("%d",c);
	return 0;
}