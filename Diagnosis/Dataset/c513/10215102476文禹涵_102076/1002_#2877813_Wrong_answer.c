#include<stdio.h>
 
int main()
{
	int T,j;
	char s[61];
	scanf("%d",&T);
	for(j=0;j<T;j++){
	scanf("%s",s);
	int a[128];
	for(int i=0;i<128;i++){
		a[i] = -1;
	}

	int digit = 0,N = 1;
	char *p = s; 
    a[*p] = 1;
    while (*++p){
	if (a[*p] == -1) {
	a[*p] = digit;
	digit = digit?digit + 1:2; N++;
	}
    if (N < 2) N = 2;
    long long ans = 0;
    p = s;
	
	while (*p) ans = ans*N + a[*p++];
    printf("case #%d: \n%lld\n",j,ans);
	return 0;
}
}
}

