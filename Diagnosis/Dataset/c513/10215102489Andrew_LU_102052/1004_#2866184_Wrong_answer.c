#include<stdio.h>
#include<string.h>
int atoi(char s[]){
	int ans=0,i;
	int q=1;
	for(i=strlen(s)-1;i>=1;i--){
		ans=ans+q*(s[i]-'0');
		q*=10;
	}
	if(s[0]=='-'){
		ans=-ans;
	}
	else ans=ans+q*(s[i]-'0');
	return ans;
}
double atof(char s[]) {
    double ans=0;
    int i;
    int f;
   	for(i=strlen(s)-1;i>0;i--){
   		if(s[i]=='.') f=i;	
	}
	int q=1;
	for(int i=f-1;i>=1;i--){
		ans=ans+q*(s[i]-'0');
		q*=10;
	}
	double p=0.1;
	for(int i=f+1;i<strlen(s);i++){
		ans=ans+p*(s[i]-'0');
		p/=10;
	}
	if(s[0]=='-') ans=-ans;
	else ans=ans+q*(s[i]-'0');
	return ans;
}
void solveint(int n){
	int c=sizeof(n);
	unsigned char*p=(unsigned char*)&n;
	while (c--)
		printf("%02x ",*p++);
	printf("\n");
}
void solvedouble(double d){
	int c = sizeof(d);
	unsigned char* p = (unsigned char*)&d;
	while (c--)
		printf("%02x ",*p++);
	printf("\n");
}
int main(){ 
	char s[65];
	while (scanf("%s",s)!=EOF){
		if(strchr(s,'.')==0)
			solveint(atoi(s));
		else 
			solvedouble(atof(s));
	}
}
