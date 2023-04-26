#include <stdio.h>
#include <stdlib.h>
int max(int x, int y){
	return x>y?x:y;
}
main(int argc, char *argv[]){
	int t, i, j, k;
	scanf("%d", &t);
	for(i = 0; i < t; ++i){
		char s1[90],s2[90],s[90];
		scanf("%s%s%s", &s1, &s2, &s);
		int l1 = strlen(s1), l2 = strlen(s2), l = strlen(s);
		int begin1 = -1, begin2 = -1, end1 = -1, end2 = -1;
		for(j = 0; j < l; ++j){
			if(s[j] == s1[0]){
				int flag1 = 1;
				for(k = 0; k < l1; ++k){
					if(s[j + k] != s1[k]){
						flag1 = 0;
						break;
					}
				}
				if(flag1 && (begin1 == -1))	begin1 = j;
				if(flag1)	end1 = j;
			}
			if(s[j] == s2[0]){
				int flag2 = 1;
				for(k = 0; k < l2; ++k){
					if(s[j + k] != s2[k]){
						flag2 = 0;
						break;
					}
				}
				if(flag2 && (begin2 == -1))	begin2 = j;
				if(flag2)	end2 = j;
			}
		}
		printf("case #%d:\n", i);
		int maxn = 0;
		if((begin1 == -1) || (begin2 == -1)){
			printf("0\n");
		}
		else{
			if(end2 >= begin1)	maxn = max(maxn, end2 - begin1 - l1);
			if(end1 >= begin2)	maxn = max(maxn, end1 - begin2 - l2);
			printf("%d\n", maxn);
		}
	}
	return 0;
}