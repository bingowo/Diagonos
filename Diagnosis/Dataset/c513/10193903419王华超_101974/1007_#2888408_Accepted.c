#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void trans(int num,char *p){
	int ys;
	while(num){
		ys=num%2;
		*p=ys+'0';
		p++;
		num=num/2;
	}
	*p='\0';
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
		char s[32];
		int n,len=1;
		scanf("%d",&n);
		trans(n,s);
		for(int j=0;j<strlen(s)-1;j++){
			int jlen=1;
			while(s[j]!=s[j+1]&&j<strlen(s)-1){
				jlen++;
				j++;
			}
			if (jlen>len){
				len=jlen;
			}
		}
		printf("case #%d:\n%d\n",i,len);
	} 
    return 0;
}