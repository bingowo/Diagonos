#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int main(int argc, char *argv[]) {
	int n,i,j,len;
	char s[100];
	scanf("%d\n",&n);
	for(j=0;j<n;j++){
	printf("case #%d:\n",j);
		scanf("%s\n",s);
		len=strlen(s);
		char a[100]={0};
		int g=0;
		for(i=0;i<len;i++){
		if(s[i]=='-')
	a[i]=-1;
	if(s[i]=='1')
	a[i]=1;
	if(s[i]=='0')
	a[i]=0;
		for(i=0;i<len;i++){
	g+=a[i]*pow(3,len-i-1);}
		
		printf("%d\n",g);
		
}

	}
	
	
	return 0;
}
