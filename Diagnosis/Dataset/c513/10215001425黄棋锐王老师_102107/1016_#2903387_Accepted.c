#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int main(){
	int N,R;
	scanf("%d %d",&N,&R);
	char s[2000]={'\0'};
	int t=0,i=0;
	do{ t=N%R;
	 N=N/R;
	if(t<0) {
		t=t-R;
		N=N+1;
	}
	if(0<=t&&t<=9)	s[i++]='0'+t;
	else if(10<=t&&t<=35) s[i++]='A'+t-10;
	}while(N!=0);
	for(i=i-1;i>=0;i--) printf("%c",s[i]);
	return 0;
}