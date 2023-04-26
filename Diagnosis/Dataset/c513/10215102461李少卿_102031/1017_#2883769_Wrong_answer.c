#include<stdio.h>
#include<string.h>
int RomanToInt(char *s){
	int sum=0;
	while(*s){
		if(*s == 'V') sum+=5;
		else if(*s == 'L') sum+=50;
		else if(*s == 'D') sum+=500;
		else if(*s == 'M') sum+=1000;
		else if(*s == 'I'){
			if(*(s+1)=='V'||*(s+1)=='X')sum-=1;
			else sum+=1;
		}
		else if(*s == 'X'){
			if(*(s+1)=='L'||*(s+1)=='C')sum-=10;
			else sum+=10;
		}
		else if(*s=='C'){
			if(*(s+1)=='D'||*(s+1)=='M')sum-=100;
			else sum+=100;
		}
		s++;
	}
	return sum;
	return 0;
}
int main(){
	char c[50];
	int i=0;
	while(	scanf("%c",&c[i++])!=EOF);
	
	char *p = c;
	int sum = RomanToInt(p);
	printf("%d",sum);
	return 0;
	
}