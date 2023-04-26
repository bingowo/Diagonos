#include<stdio.h>

unsigned int three(char s[])
{
unsigned int ret = 0;
	char *p = s;
	while(*p){
		if(*p == '1')
		ret = ret * 3 + 1;
		else if(*p == '0')
		ret = ret * 3 + 0;
		else if(*p == '-' )
		ret = ret *3 -1;
	p++;
	}
	
	return ret; 

}
int main(){
	int i,t;

	scanf("%d",&t);
	for( i=0;i<t;i++){
	    unsigned int sum;
		char s[30];
		scanf("%s",s);
		sum=three(s) ;
		printf("case #%d:\n",i);
		printf("%u\n",sum);
	}
	return 0;
}