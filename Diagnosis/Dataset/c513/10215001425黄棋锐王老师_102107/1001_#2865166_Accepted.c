#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void itob(int N,int R){
	char s[100];
	int sign=1,i=0,j=0,a;
	 if(N<0) N=-N,sign=-1;
	 while(N>0){
	 	a=N%R;
	 	if(0<=a&&a<=9) s[i]='0'+a; 
	 	else if(10<=a&&a<=35) {
	 		s[i]='A'+a-10;
		 }
		 N=N/R;
			 i++;
	 }
	 if(sign==-1) s[i++]='-';
	 s[i]='\0';
	 for(j=i-1;j>=0;j--) printf("%c",s[j]);
}

int main(int argc, char *argv[]) {
	int T,N,R,i;
	scanf("%d\n",&T);
	for(i=0;i<T;i++){
		scanf("%d %d",&N,&R);
		itob(N,R);
		printf("\n");
	} 
	return 0;
}