#include<stdio.h>
#include<string.h>
int qq[50]={0};
int tt[50];
int ad(int t){
	int i,j;
	for(i=0;i<=49;i++){
		tt[i]=0;
	}	
	for(i=1;i<=t;i++){
		for(j=0;j<50;j++){
			tt[j]+=qq[j];
			if(tt[j]>=10){
				tt[j]-=10;
				tt[j+1]++;
			}
		}
	}
}
int main(){
	int prime[26]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,91,97};
	char a[1005];
	int i,j;
	int q;
	int t1[26]={0},t2[26]={0};
	qq[0]=1;
	int ans[50]={0};
	scanf("%s",a);
	int cnt1=0,cnt2=0;
	for(j=strlen(a)-1;j>=0;j--){
		if(a[j]==','){
			cnt1++;
			q=1;
		}
		else{
			t1[cnt1]=t1[cnt1]+q*(a[j]-'0');
			q=q*10;
		}
	}
	q=1;
	for(i=0;i<=cnt1;i++){
		ad(t1[i]);
		for(j=0;j<49;j++){
			//printf("%d\n",tt[j]);
			ans[j]+=tt[j];
			if(ans[j]>=10){
				ans[j]-=10;
				ans[j+1]++;
			}
		} 
		ad(prime[i]);
		for(j=0;j<50;j++){
			qq[j]=tt[j];
		}
	}
	int f;
	for(i=49;i>=0;i--){
		if(ans[i]!=0) f=1;
		if(f==1){
			printf("%d",ans[i]);
		}
	}
}