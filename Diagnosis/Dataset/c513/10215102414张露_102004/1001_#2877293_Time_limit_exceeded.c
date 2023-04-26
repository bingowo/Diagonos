#include<stdio.h>
int main(){
	char table[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    int R,N,s,i=0;
    int flag=0;
    int a[32]={0};
    for(i=0;i>=0;i++){
    	scanf("%d%d",&N,&R);
    	if(N<0){
    		flag=1;
    		N=-N;
		}
		if(N==0){
			printf("0");
		}
    	while(N>0){
        a[i++]=N%R;
        N=N/R;
    	}
    	if(flag){
    		printf("-");
		}
    for(i=i-1;i>=0;i--){
    	s=a[i];
    	printf("%c",table[s]);
    	}
    printf("\n");
	}
    return 0;
}
