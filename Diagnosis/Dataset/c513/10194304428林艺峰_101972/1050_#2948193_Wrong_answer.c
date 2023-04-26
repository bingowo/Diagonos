#include <stdio.h>
#include <stdlib.h>
main(int argc, char *argv[]){
	int t, i, j, k;
	scanf("%d", &t);
	for(i = 0; i < t; ++i){
		char s1[90],s2[90],s[90];
		scanf("%s%s%s", &s1, &s2, &s);
		int pos1 = -1, pos2 = -1, l1 = strlen(s1), l2 = strlen(s2), l = strlen(s);
		for(j = 0; j < l; ++j){
			if(s[j] == s1[0]){
				int flag1 = 1;
				for(k = 0; k < l1; ++k){
					if(s[j + k] != s1[k]){
						flag1 = 0;
						break;
					}
				}
				if(flag1 && (pos1 == -1))	pos1 = j + l1;
			}
			if(s[j] == s2[0]){
				int flag2 = 1;
				for(k = 0; k < l2; ++k){
					if(s[j + k] != s2[k]){
						flag2 = 0;
						break;
					}
				}
				if(flag2)	pos2 = j;
			}
		}
		printf("case #%d:\n", i);
		if((pos1 == -1) || (pos2 == -1))	printf("0\n");
		else{
			printf("%d\n", pos2 - pos1);
		}
	}
	return 0;
}