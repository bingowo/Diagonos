#include <stdio.h>
int q;
int table[123];
int r(char num[]){
	int j,k;
	q=2;
	table[num[0]]=1;
	for(j=1;num[j];j++){
		if(num[j]!=num[0]){
			table[num[j]]=0;
			break;
		}
	}
	for(k=j+1;num[k];k++){
		if(table[num[k]]==-1){
			table[num[k]]=q++;
		}
	}
	return num[j]?q:1;
}
long long int rtosh(int n,char num[]){
	long long int ret=0;
	int i;
	for(i=0;num[i];i++){
		ret=ret*n+table[num[i]];
	}
	return ret;
}
int main(){
	int t,i,j; 
	scanf("%d",&t); 
	char num[70];
	for(i=0;i<t;i++){
		for(j=0;j<123;j++)table[j]=-1;
		scanf("%s",num);
		printf("case #%d:\n%lld\n",i,rtosh(r(num),num));
		
	}
	
}