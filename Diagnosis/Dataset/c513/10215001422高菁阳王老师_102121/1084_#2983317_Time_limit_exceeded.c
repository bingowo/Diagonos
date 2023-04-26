#include <stdio.h>
#include <stdlib.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void res(int m){
	int s[20]={0};
	int i,j,k=0,x;
	s[19]=1;
	for(j=0;j<m;j++){
      for(i=19;i>=0;i--)
      	s[i]*=2;
      	for(i=19;i>=0;i++)
		  if(s[i]>=10){
      		s[i-1]+=s[i]/10;
      		s[i]=s[i]%10;
		  }
      }
	  
	while(s[k]==0) k++;
       for(x=k;x<20;x++)
	printf("%d",s[x]);
	printf("\n");
}
int main(int argc, char *argv[]) {
	int n,k,m;
	scanf("%d",&n);
	for(k=0;k<n;k++){
		scanf("%d",&m);
		printf("case #%d:\n",k);
		if(m==0) printf("1\n");
		else res(m);
		
		
		}return 0;
	
	
}
	