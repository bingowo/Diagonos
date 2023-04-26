#include<stdio.h>
#include<math.h>
#include<string.h>
//int prime[26]={97,91,89,83,79,73,71,67,61,59,53,47,43,41,37,31,29,23,19,17,13,11,7,5,3,2};
int prime[26]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,91,97};
int main(){
	int n,i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		char a[1005],b[1005];
		int t1[26]={0},t2[26]={0};
		int ans[26]={0};
		scanf("%s%s",a,b);
		int cnt1=0,cnt2=0;
		int q=1;
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
		for(j=strlen(b)-1;j>=0;j--){
			if(b[j]==','){
				cnt2++;
				q=1;
			}
			else{
				t2[cnt2]=t2[cnt2]+q*(b[j]-'0');
				q=q*10;
			}
		}
		for(j=0;j<26;j++){
			ans[j]=t1[j]+t2[j]+ans[j];
			//printf("ans[%d]=%d\n",j,ans[j]);
			if(ans[j]>=prime[j]){
				ans[j]-=prime[j];
				ans[j+1]++;
			}
		}
		int f=0;
		printf("case #%d:\n",i);
		for(j=25;j>=1;j--){
			if(ans[j]!=0) f=1;
			if(f==1)
			 printf("%d,",ans[j]);
		}
		printf("%d\n",ans[0]);
	}
}