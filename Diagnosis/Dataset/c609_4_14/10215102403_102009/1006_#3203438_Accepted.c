#include<stdio.h>
int main(){
	int t;
	scanf("%d\n",&t);
	int f=t;
	while(t>0){
		char a[61]; int b[122]={0}; 
		int i=0,j=1;
		scanf("%s\n",a);
		b[a[i]]=j;
		while(a[i+1]==a[i]){
			b[a[i+1]]=j; i++;
		} i++; b[a[i]]=0; int s=i;
		while(a[++i]){
			if(b[a[i]]==0&&a[i]!=a[s]){
				j++; 
				b[a[i]]=j; 
			}
		}
		j++; i=0; long long int sum=0;
		while(a[i]!='\0'){
			sum+=b[a[i]];
			sum*=j; i++; 
		}	sum/=j;
		printf("case #%d:\n%lld\n",f-t,sum);
		t--;
	}
} 