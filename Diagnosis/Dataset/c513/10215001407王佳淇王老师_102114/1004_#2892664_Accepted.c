#include<stdio.h>
#include<string.h>
#include<stdlib.h>
 void Toint(int n){
  	int c=sizeof(n);
  	unsigned char*p=(unsigned char*)&n;
  	while(c--) printf("%0.2x ",*p++);
  	printf("\n");
  }
  void Todouble(double m){
  	int c=sizeof(m);
  	unsigned char*p=(unsigned char*)&m;
  	while(c--) printf("%0.2x ",*p++);
  	printf("\n");
  }
int main(){
	char s[31];
	while((scanf("%s",s))!=EOF){
		if(strchr(s,'.')==0)  Toint(atoi(s));
		else Todouble(atof(s));
	}
	return 0;	
}