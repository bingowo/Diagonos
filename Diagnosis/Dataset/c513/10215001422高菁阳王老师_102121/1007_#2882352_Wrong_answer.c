#include <stdio.h>
#include <stdlib.h>
#include<string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int mos(int a){
	int b,j;
	char s[100]={0};
	for(j=0;a>0;j++){
		s[j]=a%2;
		a=a/2;}
		int num=0,max=0;
		for(b=100;b>0;b--){
			if(s[b]!=s[b--])
			num++;
			if(max<num) max=num;
			if(s[b]==s[b--]){
				if(s[b-1]==0){
				num=0;
			continue;}
			else num=1;
			}
}return max;
	
}

int main(int argc, char *argv[]) {
	int n,i,k;
	scanf("%d\n",&n);
	for(k=0;k<n;k++){
		printf("case #%d:\n",k);
		scanf("%d\n",&i);
		printf("%d\n",mos(i));
		
	}
	return 0;
}