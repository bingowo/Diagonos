#include<stdio.h>
#include<string.h>
#include<ctype.h>
int count(int n){
	int co=0;
	do{
		n=n/10;
		co++;
		
	}while(n);
	return co;
}
int main(){
	char s[1000];
	scanf("%s",s);
	int len=strlen(s);
	int c[1000],i=0,k=0,z=0;
	while(s[i]){
		while(isdigit(s[i])){
			z=z*10+s[i]-'0';
			i++;
		}
		c[k]=z;
		k++;
		i++;
		z=0;
		
	}
	int max=0,l=sizeof(c)/sizeof(c[0]);
	for(int j=0;j<l;j++)	{
	if(count(c[j])>max) max=count(c[j]);}
	printf("%d\n",max);
	
} 