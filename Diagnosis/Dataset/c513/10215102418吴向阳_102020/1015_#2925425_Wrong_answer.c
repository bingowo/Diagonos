#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void readnumber(char s[100],int t[26]){
	const char* delim=",";
	char *p=strtok(s,delim);
	int m=25;
	while(p!=NULL){
		t[m]=atoi(p);
		m--;
		p=strtok(NULL,delim);
	}
	for (int i=m+1,j=25;i<j;i++,j--){
		int temp=t[i];
		t[i]=t[j];
		t[j]=temp;
	}
}

void ADD(int a[26],int b[26],int c[26]){
	int prime[26]={97,91,89,83,79,73,71,67,61,59,53,47,43,41,37,31,29,23,19,17,13,11,7,5,3,2};
	int carry=0;
	for (int i=25;i>-1;i--){
		c[i]=(a[i]+b[i]+carry)%prime[i];
		carry=(a[i]+b[i]+carry)/prime[i];
	}
}

void output(int a[]){
	int i=0;
	while (!a[i]) i++;
	for(;i<25;i++) printf("%d,",a[i]);
	printf("%d\n",a[i]);
}

int main(){
	int T=0;
	char S[100];
	scanf("%d",&T);
	for (int i=0;i<T;i++){
		int a[26]={0},b[26]={0},c[26]={0};
		scanf("%s",S);
		readnumber(S,a);
		scanf("%s",S);
		readnumber(S,b);
		ADD(a,b,c);
		printf("case #%d:\n",i);
		output(c);
	}
	return 0;
}