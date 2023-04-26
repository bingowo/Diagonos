#include<stdio.h>
char code[]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V'};
void verse(int N,int R){
	int Ns, ys, s, ii, j;
	char result[10000];
	Ns=N;
		if(Ns<0){
			printf("-");
			Ns=-Ns;
		}
		s=Ns;
		ii=0;
		while(s>0){
			ys=s%R;
			s=s/R;
			result[ii]=code[ys];
			ii++;
		};
		for(j=1;j<=ii;j++){
			printf("%c",result[ii-j]);
		};
		printf("\n");
}
int main(){
	int i,n;
	
	int N[10000];
	int R[10000];
	scanf("%d",&n);
	
	for(i=0;i<n;i++){
		scanf("%d%d",&N[i],&R[i]);
    }
    for(i=0;i<n;i++){
		verse(N[i],R[i]);
	}
	return 0;
} 