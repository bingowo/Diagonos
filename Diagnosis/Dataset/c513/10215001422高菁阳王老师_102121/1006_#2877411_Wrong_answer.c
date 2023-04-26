#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void swap(char s[]){
	int i,len,t;
	len=strlen(s);
	for(i=0;i<=len/2-1;i++){
		t=s[i];
		s[i]=s[len-1-i];
		s[len-1-i]=t;
	}
	
	
}

int main(int argc, char *argv[]) {
	int n,i,j,len,k=0;
	long int g=0;
	char s[100];
	scanf("%d\n",&n);
	getchar();
	for(j=0;j<n;j++){
	printf("case #%d:\n",j);
	for(;n>0;n--){
		scanf("%s\n",s);
		swap(s);
		len=strlen(s);
		for(i=0;i<len,k<len;i++,k++){
		if(s[i]=='-')
	s[i]=-1;
	g+=s[i]*pow(3,i);}
		}
		printf("%ld\n",g);
		
		

	}
	
	
	return 0;
}