#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 void er(int x ,int i,char*bb){ 
	char b[15];
	char t;
	int j,k=0,g=i;
	for(j=0;j<15;j++) b[j]='0';
	while(x!=0){
		b[k++]=x%2+'0';
		x=x/2;
	}	
	for(j=0;j<i;j++,i--){
		t=b[j];b[j]=b[i];b[i]=t;
	}
	for(j=0;j<g;j++) bb[j]=b[j];

}
 void chu(char*p){
 	int l=strlen(p);
 	char a[4]={"\0"};
 	int j,zhi,wei=4,k;
 	char d[2000]={'0','0','0','1'};
 	char b[15];
 	er(l,10,b);
 	for(k=0;k<10;) d[wei++]=b[k++];
 	while(*p){
	 for(j=0;*p&&(j<3);j++,p++) a[j]=*p;
	 zhi=atoi(a);
	 if(j==3){	er(zhi,10,b);
	 	for(k=0;k<10;) d[wei++]=b[k++];
	 } 
	 else if(j==2){
	 	er(zhi,7,b);
	 	for(k=0;k<7;) d[wei++]=b[k++];
	 }
	 else if(j==1){
	 	er(zhi,4,b);
	 	for(k=0;k<4;) d[wei++]=b[k++];
	 }
	 p++;
 } 	d[wei]='\0';
 	printf("%s",d);
}
int main()
{  char s[1000];
	scanf("%s",s);
	chu(s); 
  return 0;
}

