#include<stdio.h>
int s[15],ans[15],cnt,t;
int muti(){
	int sum[15]={0};
	for(int i=0;i<t;i++){
		for(int j=0;j<cnt;j++){
			sum[j+i]+=ans[i]*s[j];
			if(sum[j+i]>=10){
				sum[j+i+1]+=sum[j+i]/10;
				sum[j+i]=sum[j+i]%10;
			}
		}
	}
	for(int i=0;i<=t;i++){
		ans[i]=sum[i];
	}
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int a,b;
		cnt=0;
		scanf("%d%d%d",&a,&b,&t);
		while(a>0 && cnt<t){
			s[cnt]=a%10;
			ans[cnt]=s[cnt];
			cnt++;
			a/=10;
		}
		for(int j=0;j<b-1;j++){
			muti();
			/*for(int k=t-1;k>=0;k--){
				printf("%d",ans[k]);
			}
			printf("\n");*/
		}
		printf("case #%d:\n",i);
		for(int j=t-1;j>=0;j--){
			printf("%d",ans[j]);
		}
		printf("\n");
	}
	
}