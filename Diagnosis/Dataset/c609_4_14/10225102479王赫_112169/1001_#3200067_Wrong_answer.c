#include<stdio.h>
int main()
{
	int T,m=0;
	scanf("%d\n",&T);
	char table[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	for(m=0;m<T;m++){
	    int N ,R;
		scanf("%d %d\n",&N,&R);
		int k=0,a[33],sign=1;
		if(N<0){
		    sign=-1;N=-N;
		}
		do{
		    int r=N%R;
		    a[k++]=table[r];
		    N/=R;
		}while(N);
		if(sign<0)printf("-");
		for(k=k-1;k>=0;k--){
		    printf("%c",a[k]);
		    printf("\n");
		}
	}
	return 0;
}