#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
long long R(long long x,long long y){
	if((x-y)%2==0) return 0;
	else return 1;
}
int main(){
	char s[2000];
	scanf("%s",s);//a+bi=(qr+q1i)*(-1+i)+r得到qr=(r-a+b)/2,qi=(r-a-b)/2
	 char*p;
	 long long qr,qi,qrr,qii,r,d=0;
	 p=strchr(s,'i');
	 if(p==NULL) qr=atoi(s),qi=0; // 只有a 
	 if(p!=NULL){
	 	*p='\0';
	 	p=p-1;
	 	int j=strlen(s)-1,l;
	 	l=j;
	 	if(strcmp(s,"i")) qr=0,qi=1;
//	 	else if (strcmp(s,"-i") )qr=0,qi=-1;
	 	for(;*p!='+'&&*p!='-'&&j!=-1;j--,p--);
	 	if(*p=='+'&&j==l) d=1,qi=1;
	 	else if(*p=='-'&&j==l&&j>0) d=1, qi=-1; 
	 	else if(*p=='-'&&j==l&&j==0) qr=0, qi=-1; 
	 	else if(j==-1) qr=0,qi=atoi(s);
	 	else if(*p=='-'&&j<l&&j==0) qr=0,qi=atoi(s);
	 	else if(*p=='-'&&j<l&&j>0) d=1,qi=atoi(p);
	 	else if(*p=='+'&&j<l) {
	 		d=1;qi=atoi(p);
		 }
	 if(d=1) {
	 	*p='\0';
	 	qr=atoi(s);
	 }
	 }

	 char i[2000];
	 int n=0;
	  do{
	  r=R(qr,qi);
	  i[n++]=r;
	  qr=(r-qr+qi)/2,qi=(r-qr-qi)/2;
	 }while(qr!=0&&qi!=0);
	 for(n=n-1;n>0;n--){
	 	printf("%c",i[n]);
	 }
		return 0;
}

