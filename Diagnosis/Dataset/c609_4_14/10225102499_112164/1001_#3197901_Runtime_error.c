#include<stdio.h>

int DtoR(long long x,int r){
	int c[1000],i=0,j=0,n=0,k=0;
	char num[36]={'0','1','2','3','4','5','6','7','8','9',};
	do{
		c[i]=x%r;
		x/=r;
		i++;
	}
	while(x/r>0||x%r==0);
	for(j=0;j<26;j++)
		num[i]=i+'A';
	for(k=0;k<i;k++){
		n=c[i];
		printf("%c",num[n]);
	}
}

int main(){
	int n,b[100],i=0;
	long long a[100];
	scanf("%d",&n);
	for(;i<n;i++)
		scanf("%lld %d",&a[i],&b[i]);
	for(i=0;i<n;i++){
		DtoR(a[i],b[i]);
	}
	return 0;
}