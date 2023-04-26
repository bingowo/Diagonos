#include <stdio.h>
#include <stdlib.h>
#define N 1000000 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int m[128],start=0,len=0;
	int i,t=0;
	char s[N],c;
	scanf("%s",s);
	for(i=0;i<128;i++) m[i]=-1;
	for(i=0;s[i];i++){
		c=s[i];
		if(m[c]>=t){
		t=m[c]+1;
		m[c]=i;	
		}
		else {
			m[c]=i;
			if(len<i-t+1){
				start=t;
				len=i-t+1;
			}
		}
	}
     for(int j=0;j<len;j++)
     	printf("%c",s[start+j]);
	 printf("\n");
	return 0;
}