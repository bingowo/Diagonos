#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
char buf[400];
int main(){
	long long date=-1;
	while(1){
		scanf("%s",buf);
		if(strcmp(buf,"END")==0)break;
		if(strncmp(buf,"$GPRMC",6)==0){
			int i=0,out=buf[2]^buf[1],check=0;
			for(i=3;buf[i]!='*';i++){
				out=buf[i]^out;
			}
			sscanf(buf+i+1,"%x",&check);
			if(out%65536==check){
				sscanf(buf+7,"%lld",&date);
				date=(date+80000)%240000;
			}
		} 
	}
	long long h=date/10000,m=date%10000/100,s=date%100;
	printf("%02lld:%02lld:%02lld",h,m,s);
	return 0;
}