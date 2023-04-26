#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int gcd(int x,int y){
	return x%y==0? y:gcd(y,x%y);
}
int main(){
	int n,i,j,k;
	char t[123];
	scanf("%d",&n);
	gets(t);
	for(i=1;i<=n;i++){
		char a[125];
		int l=0;
		int ans=0;
		gets(a);
		int ans1=0,ans2=0;
		for(j=0;j<strlen(a);j++) {
			int t=a[j];
			while(t>0){
				if(t%2==1) ans1++;
				t=t/2;
			}
			ans2+=sizeof(a[j])*8;
		}
		int g=gcd(ans1,ans2);
		printf("%d/%d\n",ans1/g,ans2/g);
	}
} 

