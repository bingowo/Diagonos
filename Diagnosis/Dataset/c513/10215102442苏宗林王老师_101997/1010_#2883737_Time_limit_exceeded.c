#include<stdio.h>
#include<stdlib.h> 
#include<string.h>
void pr(int a){
	int i=0,re[100];
	while(a>0){
		re[i]=a%2;
		a/=2;
		i++;
	}
	while(i<10){
		re[i]=0;
		i++;
	}
	for(int k=9;k>=0;k--){
		printf("%d",re[k]);
	}
}

int main(){
    int n=0,i=0,j=0,a,an[10000];
    char s[4],re[10000];
    while(scanf("%c",&s[i])!=0){
    	if(n==2){
    		a=100*(s[0]-'0')+10*(s[1]-'0')+s[2]-'0';
    		an[j]=a;
    		j++;
    		//把s中的十进制数转二进制
			i=-1; 
		}
    	n++;
    	i++;
	}
	//printf("ok");
	if(n%3!=0){
		if(n%3==1){
			an[j]=s[0]-'0';
		}
		else{
			an[j]=(s[0]-'0')*10+s[1]-'0';
		}
		j++;
	}
	pr(n);
	for(int m=0;m<j-1;m++){
		pr(an[m]);
	}

	return 0;
}