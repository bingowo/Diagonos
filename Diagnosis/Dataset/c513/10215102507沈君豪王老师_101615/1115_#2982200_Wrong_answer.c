#include <stdio.h>
#include <string.h>

int main(void)
{
	int t;
	scanf("%d", &t);
	for(int i = 0 ; i < t; i ++){
		int n[30] = {0};
		char s[30];
		scanf("%s", s);
		int len = strlen(s), min = 10;
		for(int i = 0 ; i < len; i ++){ 
			n[i] = s[i] - '0';
			if(n[i] < min){ min = n[i];}
		}
		int psmin, pmin;
		for(int i = len - 2 ; i >= 0 ; i --){
			if(n[i] == min){
				psmin = i + 1;
				for(int j = i + 1; j < len; j ++){
					if(n[j] > min && n[j] < n[psmin]){
						psmin = j;
					}
				}
				if(n[i] < n[psmin]){
					pmin = i;
					break;
				}
			}
		}

		int temp;
		temp = n[psmin];
		for(int i = psmin; i > pmin; i --){
			n[i] = n[i - 1];
		}
		n[pmin] = temp;
		int idx;
		printf("case #%d:\n", i);
		for(idx = 0; idx < len; idx ++){
			printf("%d", n[idx]);
		}
		printf("\n");
	}
	
	return 0;
}