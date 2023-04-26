#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

char s[10000001],t[10000001];
int main()
{
	scanf("%s",s);
	char*p;
	 long long qr,qi,a,b,d;
	 if(strchr(s,'i')==NULL) qr=atoi(s),qi=0; // 只有a 
	 else if(s[0]=='i') qr=0,qi=1;
	 else if(strchr(s,'i')&&s[0]!='i'
	 &&strchr(s,'+')==NULL&&strchr(s,'-')==NULL){
	 	p=strchr(s,'i');
	 	*p='\0';
	 	qr=0,qi=atoll(s);
	 } 
	 else if(strchr(s,'i')&&s[0]!='i'){
	 	p=strchr(s,'i');
	 	*p='\0';
	 	p=p-1;
	 	int j=strlen(s)-1,l;
	 	l=j;
		 for(;*p!='+'&&*p!='-'&&j!=-1;j--,p--);
	 	if(*p=='+'&&j==l) d=1,qi=1;
	 	else if(*p=='-'&&j==l&&j>0) d=1, qi=-1; 
	 	else if(*p=='-'&&j==l&&j==0) qr=0, qi=-1; 
	 	else if(j==-1) qr=0,qi=atoi(s);
	 	else if(*p=='-'&&j<l&&j==0) qr=0,qi=atoll(s);
	 	else if(*p=='-'&&j<l&&j>0) d=1,qi=atoll(p);
	 	else if(*p=='+'&&j<l) {
	 		d=1;qi=atoll(p);
		 }
		 else if(j==-1&&l>0) qr=0,qi=atoll(p+1);
		 if(d=1) {
	 	*p='\0';
	 	qr=atoll(s);
        }
	 }
	int i=0;
	while(qr>0&&qi>0){
		int m,n;
		m=qr%2;
		n=qi%2;
		if(m==n){
			t[i]=0;
		}
		else{
			t[i]=1;
		}
		i++;
		a=(qi-qr+t[i])/2;
		b=(t[i]-qr-qi)/2;
		qr=a;
		qi=b;
	}
	for (i=strlen(t)-1;i>-1;i--){
		printf("%c",t[i]);
	}
	printf("\n");
	return 0;
}