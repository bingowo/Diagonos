#include<stdio.h>
int main()
{
	int T,N,R,i,j,k;
	char c[1000];
	scanf("%d",&T);
	for( i=0;i<=T;i++){
	 scanf("%d %d",&N,&T);
	j=0;
	if(N<0) {
	printf("-") ; 
    N=-N;} 
    while(N>0){
    	k=N%T;
          if(k<=9)  c[j]=k+'0';
          else c[j]=k+'A'-10;
          j++;
          N/=T;
	}
	while(j>=1){
		printf("%c",c[j-1]);
		j--;
	}printf("\n");
	}
	return 0;}