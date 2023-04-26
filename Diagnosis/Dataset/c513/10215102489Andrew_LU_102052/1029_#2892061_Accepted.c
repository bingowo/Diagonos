#include<stdio.h>
#include<stdlib.h>
typedef struct{
	int s[55];
	int len;
}p;
int cmp1(const void *a, const void *b){
	return *(char *)a>*(char *)b;
}
int main(){
	int t,i,j,k;
	scanf("%d",&t);
	getchar();
	for(i=0;i<t;i++){
		int n,cnt=0;
		int len=0;
		char kk[205];
		int tt=0;
		char a[1005];
		char cc;
		for(j=0;j<204;j++) kk[j]='a';
		while(scanf("%c",&cc)){
			if(cc=='\n') break;
			else if((cc<='Z' && cc>='A')||(cc>='a')&&(cc<='z')){
				a[len++]=cc;
			}
			else{
				kk[tt]=cc;
			//	printf("%c	%d\n",kk[tt],tt);
			}
			tt++;
			//printf("%c",cc);
		}
		//for(j=0;j<len;j++){
		//	printf("%c",a[j]);
		//}
		//printf("\n");
		qsort((void *)a,len,sizeof(a[0]),cmp1);
		for(j=0;j<len;j++){
		//	printf("%c",a[j]);
		}
		//printf("\n");
		printf("case #%d:\n",i);
		for(j=0;j<204;j++){
			while(kk[j]!='a'){
				printf("%c",kk[j]);
				j++; 
				cnt++;
			}
			if(j-cnt<len) printf("%c",a[j-cnt]);
		}
		printf("\n");
	}
}