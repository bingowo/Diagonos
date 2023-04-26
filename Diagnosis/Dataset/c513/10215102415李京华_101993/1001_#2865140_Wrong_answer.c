#include <stdio.h>

int main()
{
	int T;
	scanf("%d", &T);
	char L[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	while (T--){
		int N,R;
		scanf("%d%d",&N,&R);
		char ans[64];
		int cnt = 0;
		int neg = 0;
		
		if (N < 0){
			N = -N;
			neg = 1;
		}
		
		while (N){
			ans[cnt++] = L[N % R];
			N /= R;
		}
		
		if (neg)
			ans[cnt++] = '-';
		
		
		while (cnt--)
			printf("%c",ans[cnt - 1]);
			
		if (T != 1)
			printf("\n");
	}
	return 0;
}