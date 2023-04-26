#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
int count(int n){
	int co=0;
	//算位数 
	do{
		n=n/10;
		co++;
		
	}while(n);
	return co;
}
int main(){
	char s[10000]={0};
	scanf("%s",s);
	int len=strlen(s);
	int i=0,j,k,z=0,start,max=0;
	for(;i<len;i++){
		if(isalpha(s[i])) continue;
		else{start=i;
			for(j=start;isdigit(s[j]);j++)
			{z=z*10+s[j]-'0';}
			int m=count(z);
			max=fmax(m,max);
			i=j;
		}
	}
	printf("%d",max-2);
	return 0;
} 