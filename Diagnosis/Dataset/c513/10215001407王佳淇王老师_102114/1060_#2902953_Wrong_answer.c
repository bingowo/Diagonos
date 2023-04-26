#include<stdio.h>
#include<string.h>
#include<ctype.h>
int count(int n){
	int co=0;
	do{
		n/=10;
		co++;
		
	}while(n);
	return co;
}
int main(){
	char s[1000];
	scanf("%s",s);
	int len=strlen(s);
	int c[1000],i=0,z=0;
	for(int k=0;k<len;k++){
		if(isdigit(s[k])) {
		z=z*10+s[k]-'0';}
		else {c[i]=z;i++;};
	}
	int max=0,l=sizeof(c)/sizeof(c[0]);
	for(int j=0;j<l;j++)	{
	if(count(c[j])>max) max=count(c[j]);}
	printf("%d\n",max);
	
} 