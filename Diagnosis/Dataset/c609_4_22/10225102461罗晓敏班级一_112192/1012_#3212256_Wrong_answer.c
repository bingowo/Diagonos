#include <stdio.h>
#include <math.h>
#include <string.h>
double f(char num[]){
	double ret=0;int i;
	for(i=2;num[i];i++){
		ret+=(num[i]-'0')*pow(8,1-i);
	}
	return ret;
}
int main(){
	int t,i;
	scanf("%d",&t);
	char num[60];int lnum;
	for(i=0;i<t;i++){
		scanf("%s",num);
		lnum=strlen(num);
		printf("case #%d:\n%.*f\n",i,3*(lnum-1),f(num)); //用%g输出能忽略末尾的0 
	}
} 