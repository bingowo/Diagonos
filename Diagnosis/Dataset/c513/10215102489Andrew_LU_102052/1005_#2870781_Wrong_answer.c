#include<stdio.h>
#include<string.h>
int q[505]={0};
int tt[505]={0};
int ad(int t){
	int i,j;
	for(i=0;i<505;i++){
		tt[i]=0;
	}	
	for(i=1;i<=t;i++){
		for(j=0;j<505;j++){
			tt[j]+=q[j];
			if(tt[j]>=10){
				tt[j]-=10;
				tt[j+1]++;
			}
		}
	}
}
int main(){
	int n,i,j,k,v;
	char a[55];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%s",&a);
		int ans[505]={0};
		for(j=0;j<505;j++) q[j]=0;
		q[0]=1;
		for(j=2;j<strlen(a);j++){
			int t=(a[j]-'0');
			//printf("t=%d\n",t);
			int l=0;
			ad(125);
			for(k=0;k<505;k++){
				q[k]=tt[k];	
				//printf("%d ",q[k]);
			}
			ad(t);
			
			for(v=501;v>=0;v--){
				ans[v+3]=ans[v];
				if(v<=2) ans[v]=0;
			}
			/*for(k=0;k<15;k++){
				printf("%d ",ans[k]);
			}*/
			//printf("\n");
			for(k=0;k<504;k++){
				ans[k]+=tt[k];
				if(ans[k]>=10){
					ans[k]-=10;
					ans[k+1]++;
				}
			}
			for(k=0;k<15;k++){
		//		printf("%d ",ans[k]);
			}
		//	printf("\n");
		}
		printf("case #%d:\n",i);
		printf("0.");
		int f;
		for(j=504;j>=0;j--){
			if(ans[j]!=0){
				//printf("ans=%d",j);
				f=j;
				break;
			}
		}
		for(j=1;j<=(strlen(a)-2)*3-f-1;j++){
			printf("0");
		}
		for(j=f;j>=0;j--){
			printf("%d",ans[j]);
		}
		printf("\n");
	}
	
} 