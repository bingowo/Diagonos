#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
int gcd(int m,int n)
{
	if(n<=m&&n==0) return n;
	else if(n>m) return gcd(n,m);
	else return gcd(n,m%n);
}

int a=0,b=0,c=0;
void read(char*s){
	
	int i=0,len=strlen(s),flag=1;
	if(s[0]=='x') {
		a=1;
		i++;
	}
	else if(s[0]=='-'&&s[1]=='x'){
		a==-1;
		i++;
	}
	else {
	if(s[0]=='-'&&isdigit(s[1])) flag=-1;
	for(;i<len&&isdigit(s[i]);i++)
{
    	a=a*10+s[i]-'0';
} a*=flag;
	}
	 flag=1;
    while(s[i]!='+'&&s[i]!='-') i++;
    if(s[i]=='-') flag=-1;
    i++;
    for(;i<len&&isdigit(s[i]);i++){

	 b=b*10+s[i]-'0';
    }b*=flag;
   if(i==len) {
    	c=b;
    	b=0;
   }
   
	else{
		flag=1;
		while(s[i]!='+'&&s[i]!='-') i++;
    if(s[i]=='-') flag=-1;
    i++;
    for(;i<len&&isdigit(s[i]);i++){

	 c=c*10+s[i]-'0';
    }c*=flag;	
	}
	
	
}
int main(){
	char s[50];
	scanf("%s",&s);
	read(s);
	//printf("%d %d %d",a,b,c);
     int d=b*b-4*a*c;
     //printf("%d",d);
	if(d<0) printf("No Answer!");
	if(d=0) printf("%d %d %d %d",2*a/gcd(2*a,b),b/gcd(2*a,b),2*a/gcd(2*a,b),b/gcd(2*a,b));
	else {
		int a1=2*a/gcd(2*a,(b+(int)sqrt(d)));
		int c1=(b+(int)sqrt(d))/gcd(2*a,(b+(int)sqrt(d)));
		int a2=2*a/gcd(2*a,((int)sqrt(d)-b));
		int c2=((int)sqrt(d)-b)/gcd(2*a,((int)sqrt(d)-b));
		
		if(a1>a2) printf("%d %d %d %d",a1,c1,a2,c2);
		else if(a1<a2) printf("%d %d %d %d",a2,c2,a1,c1);
		else {
			if(c1<c2) printf("%d %d %d %d",a2,c2,a1,c1);
			else printf("%d %d %d %d",a2,c1,a1,c2);
		}
	}
	return 0;
}