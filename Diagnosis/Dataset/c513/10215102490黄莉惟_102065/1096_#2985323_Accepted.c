#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
	int t,i,j;
	scanf("%d",&t);
	for(i=0;i<t;i++){
		int n,a,b;
		int equal=1;
		int code[101][101]={{0,0}};
		int codein[101]={0};
		int codeout[101]={0};
		scanf("%d",&n);
		for(j=0;j<n;j++){
			scanf("%d %d",&a,&b);
			if(code[a][b]!=1){
				codein[a]++;
				codeout[b]++;
				code[a][b]=1;
			}
		}
		for(j=0;j<101;j++){
			if(codein[j]>1){
				equal=0;
			}else if(codein[j]&&codeout[j]){
				equal=0;
			}
		}
		if(equal==0){
			printf("Poor dxw!\n");
		}else{
			printf("Lucky dxw!\n");
		}
	}
}
