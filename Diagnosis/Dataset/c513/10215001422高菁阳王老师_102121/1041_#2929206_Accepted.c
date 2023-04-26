#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int Max(int a,int b){
	if(a>b) return a;
	else return b;
}
int main(int argc, char *argv[]) {
	char s[50];
	int max=1,cnt[50],len;
	cnt[0]=1;
	scanf("%s",s);
	len=strlen(s);
	if(len==1) printf("1");
	else{for(int i=1;i<len;i++){
		if(s[i]!=s[i-1]) {
		cnt[i]=cnt[i-1]+1;
	max=Max(cnt[i],max);}
	else cnt[i]=1;
	}
	printf("%d",max);}
	return 0;
}