#include<stdio.h>
#include<string.h>
int solve(int n, int p, int m, int t){
	int ret = 0;
	int temp1[100000];
	int temp2[100000];
	temp1[0] = p;
	temp1[1] = -1;
	for(int i=1;i<=m;i++){
		int tep1 = 0;
		int tep2 = 0;
		while(temp1[tep1]!=-1){
			if(temp1[tep1]==1){
				temp2[tep2++]=2;
			}
			else if(temp1[tep1]==n){
				temp2[tep2++]=n-1;
			}
			else{
				temp2[tep2++]=temp1[tep1]-1;
				temp2[tep2++]=temp1[tep1]+1;
			}
			tep1++;
		}
		temp2[tep2++] = -1;
		for(int j=0;j<tep2;j++){
			temp1[j] = temp2[j];
		}
	}
	for(int i=0;;i++){
		if(temp1[i]==t)ret++;
		if(temp1[i]==-1)break;
	}
	return ret;
}
int main(){
	int n, p, m, t;
	int cas;
	scanf("%d", &cas);
	int ret[100];
	for(int i=0;i<cas;i++){
		scanf("%d%d%d%d", &n,&p,&m,&t);
		ret[i] = solve(n, p, m, t);	
	}
	for(int j=0;j<cas;j++){
		printf("%d\n", ret[j]);
	}
	return 0;
}