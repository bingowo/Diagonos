#include<stdio.h>

int power(x,n){
	int power=1;
	for(;n>0;n--)
		power*=x;
	return power;
}

int TtoD(char *a){
	int i=0,n,answer;
	int b[20];
	for(n=0;a[n]!=0;n++){
		if(a[n]=='1'||a[n]=='0')
			b[n]=a[n]-'0';
		if(a[n]=='-')
			b[n]=-1;
	}
	while(n>0){
		answer+=b[n-1]*power(3,i);
		n--,i++;
	}
	return answer;
}

int main(){
	int i,T;
	char a[10][20]={0};
	scanf("%d",&T);
	for(i=0;i<T;i++){
		scanf("%s",a[i]);
		printf("case #%d:\n%d\n",i,TtoD(a[i]));
	}
	return 0;
} 