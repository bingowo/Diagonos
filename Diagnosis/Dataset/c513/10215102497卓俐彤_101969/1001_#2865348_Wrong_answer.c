#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define A 5000

int main(){
	int T;
	scanf("%d",&T);
	for(int i=0;i<T;i++){
		int N;
		int R;
		scanf("%d %d",&N,&R);
		if(N<0){
			printf("-");
			N*=(-1);
		}
		if(R<10){
			char m[A];
			int n,i=0;
            while(N>=R){
                n=N%R;
                m[i++]='0'+n;
                N/=R;
            }
            m[i]=N;
            m[i+1]="\0";
            for(int j=i;j>=0;j--)printf("%d",m[j]);
		}
		else{
            char m[A];
            int n,i=0;
            while(N>=R){
                n=N%R;
                if(n<10){m[i++]='0'+n;}
                else{
                    char c='A';
                    m[i++]=c+n-10;
                }
                N/=R;
            }
            m[i]=N;
            m[i+1]="\0";
            for(int j=i;j>=0;j--){
                if(isdigit(m[j]))printf("%d",m[j]);
                else{printf("%c",m[j]);}
            }
		}
		printf("\n");
	}
	return 0;
}
