#include <stdio.h>
#include<string.h>
#include<ctype.h>
long long s[120] = {0};
long long con(int n){
	if(n == 1){
		s[n] = 1;return 1;
	}
	if(n == 2){
		s[n] = 2;return s[n];
	}
	if(n == 3){
		s[n] = 4;return s[n];
	}
	if(n == 4){
		s[n] = 8;return s[n];
	}
	if(n > 4){
		if(s[n] != 0)return s[n];
		else {
			s[n] = con(n-1) + con(n-2) + con(n-3) + con(n-4); return s[n];
		}
	}
}
int main(){
	int i, t, n;
	scanf("%d", &n);
	for(i = 0; i < n; i++){
		scanf("%d", &t);
		printf("case #%d:\n", i);
		printf("%lld\n", con(t));
	}
    
	return 0;
}

		
	