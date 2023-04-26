#include <stdio.h>

/*

*/

int main()
{
    int T,t;
	scanf("%d",&T);
	for(t = 0; t < T; t++){
		char s[61];
		scanf("%s",s);
		int a[128];
		int i;
		for(i = 0; i < 128; i++){
			a[i] = -1;
		}
		int R = 0;
		char *p = s;
		a[*p] = 1;
		while(*(p++) != '\0'){
			if(a[*p] == -1){
				a[*p] = R;
				R = (R ? (R + 1):2);
			}
		}
		if( R < 2){
			R = 2;
		}
		long long int N = 0;
		p = s;
		while(*p){
			N = N * R + a[*p++];
		}
		printf("case #%d:\n%lld\n",t,N);
	} 
	return 0;
}