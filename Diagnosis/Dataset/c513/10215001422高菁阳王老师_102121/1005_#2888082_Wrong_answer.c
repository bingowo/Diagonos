#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int n,k,i,c;
	char s[100];
	scanf("%d",&n);
	for(k=0;k<n;k++){
		printf("case #%d:\n",k);
		scanf("%s",s);
		long double num=0;
		c=strlen(s);
		i=c-1;
		while(s[i]!='.'){int tmp=s[i]-'0';
  num=num*0.125+tmp;
  printf("num :%lf\n",num);
  i--;}
		num*=0.125;
		printf("%.50g\n",num);
		
	}
	
	return 0;
}