#include<stdio.h>

int three(char s[])
{
	int ret = 0;
	char *p = s;
	while(*p){
		if(*p == '1')
		ret = ret * 3 + 1;
		else if(*p =  '0')
		ret = ret * 3 + 0;
		else if(*p == '-' )
		ret = ret *3 -1;
	}
	return ret; 

}
int main(){
	int i,t,sum;
	scanf("%d",&t);
	for(i=0;i<t;i++){
		char s[30];
		scanf("%s",s);
		sum=three(s) ;
		printf("case#%d\n",i);
		printf("%d",sum);
	}
	return 0;
}