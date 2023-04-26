#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
    int t,i,j,result,a,n,k;
    char s[1000];
    int len[2];
    scanf("%d",&t);
    for(i=0;i<t;i++){
    	scanf("%d",&n);
    	j=0;
    	while(n!=0){
    		a=n%2;n=n/2;
    		s[j++]=a+'0';
		}  //二进制
		len[0]=1;len[1]=1;
		for(k=1;k<j;k++){
			if(s[k]==s[k-1])len[0]=1;
			else len[0]++;
			len[1]=len[0]>len[1]?len[0]:len[1];
		} 
		printf("case #%d:\n%d\n",i,len[1]);
	}
	return 0;
}