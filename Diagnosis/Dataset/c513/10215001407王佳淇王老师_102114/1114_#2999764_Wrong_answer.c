#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
int abss(int n){
	if(n<0) return -n;
	else return n;
}
int gcd(int m,int n)
{
	if(n<=m&&n==0) return m;
	else if(n>m) return gcd(n,m);
	else return gcd(n,m%n);
}

int a=0,b=0,c=0;
void read(char*s){
	//读a 
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
	//读b 
	 flag=1;
    while(s[i]!='+'&&s[i]!='-') i++;
    if(s[i]=='-') flag=-1;
    if(s[i+1]=='x') {b=flag;i++;}
    else if(isdigit(s[i+1]))
	{
	i++;
    for(;i<len&&isdigit(s[i]);i++){

	 b=b*10+s[i]-'0';
    }b*=flag;
}
   if(i>=len) {
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
	double x=sqrt(d);
	if(x-(int)x!=0) printf("No Answer!");
	else{
		int y1=b-(int)x;
		int y2=b+(int)x;
		int a1,a2;
		if(y1==0) a1=1;
		if(y2==0) a2=1;
		if(y1!=0) {
			a1=2*a/gcd(abss(2*a),abss(y1));
			y1=y1/gcd (abss(2*a),abss(y1));
		} 
			if(y2!=0) {
			a2=2*a/gcd(abss(2*a),abss(y2));
			y2=y2/gcd (abss(2*a),abss(y2));
		} 
		if(a1<a2) printf("%d %d %d %d",a1,y1,a2,y2);
		else if(a1>a2) printf("%d %d %d %d",a2,y2,a1,y1);
		else {
			if(y1>y2) printf("%d %d %d %d",a2,y2,a1,y1);
			else printf("%d %d %d %d",a2,y1,a1,y2);}}
	return 0;
}