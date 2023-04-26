#include<stdio.h>
int main()
{
	int i,j,m,n;
	int T;
	scanf("%d",&T);
	while(T--){
		int q,cnt=0;
		scanf("%d",&q);
		for(i=(q-q/4*4);i<=q;i+=4){
			for(j=(i-i/3*3);j<=i;j+=3){
				for(m=(j-j/2*2);m<=j;m+=2){
					for(n=m;n<=m;n++)
						cnt++;
				}
			}
		}
		printf("%d\n",cnt);
	}
	
	return 0;
} 