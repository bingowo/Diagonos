#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int bin(int n,char* num){
	int i=0,b;
	while(n>0){
		b=n%2;n=n/2;
		num[i]=b+'0';
		i++;
	}
	return i;
}

int main() {
	int t,len,i,j,n;
	char num[1000];
	int length[]={1,1};
	scanf("%d",&t);
	for(i=0;i<t;i++){
		scanf("%d",&n);
		len=bin(n,num);  //二进制字符串 
		for(j=1;j<len;j++){
			if(num[j]==num[j-1])length[0]=1;
			else length[0]++;
			length[1]=length[0]>length[1]?length[0]:length[1];
		}
		printf("case #%d:\n%d\n",i,length[1]);
	}
	return 0;
}