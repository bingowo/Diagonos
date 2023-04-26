#include <stdio.h>
#include <stdlib.h>
#include<string.h>
char *jz="0,1,2,3,4,5,6,7,8,9,A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z"; 
int main() {
	int num,i=1,j,k,R;char x[32];long long int N;
	scanf("%d",&num);
	void zhuan(int N,int R);
	while(i<=num){
		j=0;N=0;
		scanf("%s",x);j=strlen(x);
		scanf("%d",&R);
		if(x[0]=='-'){N=atoi(x+1);printf("-");zhuan(N,R);
		}
		else{n=atoi(x);zhuan(N,R);
		}
		printf("\n");i++;
	}
	return 0；
}
void zhuan(int N,int R){
	int c;char str1[100];int i=0,k;
	while(N>0){
		c=N%R;str1[i]=jz[c];
		N=N/R;
		i++;
	}
	str1[i]='\0';for(k=i-1;k>=0;k--) printf("%c",str1[k]);
}