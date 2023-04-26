#include<stdio.h>
int main()
{
	int i, j, k, N, m , a[50] = {0};
	int t;
	scanf("%d",&t);
	for(m=0;m<t;m++){
	    printf("case #%d:\n",m);
	    scanf("%d", &N);
	    a[49] = 1;
	    k = 0;
	    for(i=0;i<N;i++)
		    for (j = 49; j >= 0; j--){
		        a[j] = a[j] * 2+k;
			    k = a[j] / 10;
			    a[j] = a[j] % 10;
		    }
	    for (i = 0; i < 50; i++){
	        if (a[i] != 0) break;
	    }
	    for (i; i < 50; i++)
		    printf("%d", a[i]);
	}
	return 0;
}
