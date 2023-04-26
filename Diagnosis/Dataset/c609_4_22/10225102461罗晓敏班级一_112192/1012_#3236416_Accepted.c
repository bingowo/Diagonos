#include <stdio.h>
#include <math.h>
#include <string.h>
void f(char num[],int ans[],int lnum){
	int i=0,j,rest,temp;
	for(j=lnum-1;j>1;j--){
		temp=ans[0];
		ans[0]=((num[j]-'0')*10+temp)/8;
		rest=((num[j]-'0')*10+temp)%8;
		for(i=1;i<3*(lnum-2);i++){
			temp=ans[i];
			ans[i]=(rest*10+temp)/8;
			rest=(rest*10+temp)%8;
		}
	}
}
int main(){
	int t,i,j,k;
	scanf("%d",&t);
	char num[60];
	int lnum;
	for(i=0;i<t;i++){
		scanf("%s",num);
		lnum=strlen(num);
		int ans[3*(lnum-2)];
		printf("case #%d:\n0.",i); 
		for(j=0;j<3*(lnum-2);j++){
			ans[j]=0;
		}
		f(num,ans,lnum);
		for(j=3*(lnum-2)-1;ans[j]==0;j--);//排除末尾的0
		for(k=0;k<j+1;k++){
			printf("%d",ans[k]);
		}
		printf("\n");
	}
} 