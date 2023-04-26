#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define X 100



int main(){
	int T;
	scanf("%d",&T);
	int A[X];
	for(int i=0;i<2*T;i++){
        scanf("%d",&A[i]);
	}
	A[2*T]='\0';
	for(int j=0;j<T;j++){
        int N=A[2*j],R=A[2*j+1];
        char answer[X];
        int n,m=0;
        while(N>=R){
            n=N%R;
            if(n<10){answer[m++]='0'+n;}
            else{answer[m++]='A'+n-10;}
            N/=R;
        }
        if(N<10){answer[m]='0'+n;}
        else{answer[m]='A'+n-10;}
        answer[m+1]='\0';
        for(int k=m;k>=0;k--)printf("%c",answer[m]);
        printf("\n");
	}
	return 0;
}
