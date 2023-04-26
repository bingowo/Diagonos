#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int n,k,cnt=0;
	char s[100];
	scanf("%d",&n);
	for(k=0;k<n;k++){
		printf("case #%d:\n",k);
do{
		scanf("%s",s);
		int len=strlen(s);
		for(int i=0;i<len;i++){
		if(s[i]=='a'||s[i]=='A'&&len==1) break;
		if(s[i]=='t'||s[i]=='T'&&s[i+1]=='h'&&s[i+2]=='e'&&len==3)	 break;
		if(s[i]=='a'||s[i]=='A'&&s[i+1]=='n'&&len==2) break;
		if(s[i]=='o'||s[i]=='O'&&s[i+1]=='f'&&len==2) break;
		if(s[i]=='f'||s[i]=='F'&&s[i+1]=='o'&&s[i+2]=='r'&&len==3) break;
		if(s[i]=='A'||s[i]=='a'&&s[i+1]=='n'&&s[i+2]=='d'&&len==3) break;
		}cnt++;
		
	}while(getchar()!='\n');
	printf("%d\n",cnt);
}
	return 0;
}