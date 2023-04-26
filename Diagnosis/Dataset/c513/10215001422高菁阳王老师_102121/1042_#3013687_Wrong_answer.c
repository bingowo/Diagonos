#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char d[100];
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void answer(char*a,int len,int l,int r){
	if(l==r) return;
	for(;l!=r;l++){
		d[len]=a[l];
		d[len+1]=0;
		printf("%s\n",d);
		answer(a,len+1,l+1,r);
	}
}
int main(int argc, char *argv[]) {
	int n,k;
	char s[17];
	scanf("%d",&n);
	for(k=0;k<n;k++){
		scanf("%s",s);
		printf("case #%d:\n",k);
		int b[100]={0},count=0;
		char c[53]={0};
		for(int i=0;i<strlen(s);i++)
		{b[s[i]]++;}
		for(int i=0;i<26;i++){
			if(b[i+'A']) c[count++]='A'+i;
		}
		for(int i=0;i<26;i++){
			if(b[i+'a']) c[count++]='a'+i;
		}
		answer(c,0,0,strlen(c));
	}
	return 0;
}