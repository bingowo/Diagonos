#include<stdio.h>
int main(){
	int t;
	scanf("%d\n",&t);
	int f=t;
	while(t>0){
		char a[60]; int b[80]={-1}; 
		int i=0,j=1;
		scanf("%s\n",a);
		b[a[i]]=j;
		while(a[i+1]&&(a[i+1]==a[i])){
			b[a[i+1]]=j; i++;
		} b[a[i]]=0;
		while(a[++i]){
			if(b[a[i]]==-1){
				j++; 
				b[a[i]]=j;
			}
		}
		j++; i=0; int sum=0;
		while(a[i]!=EOF){
			sum+=b[a[i]];
			sum*=j;
		}	sum/=j;
		printf("case #%d:\n&d\n",f-t,sum);
		t--;
	}
} 