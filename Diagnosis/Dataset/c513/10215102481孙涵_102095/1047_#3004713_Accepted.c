#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <math.h>
#include <ctype.h>


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int T;
	scanf("%d",&T);
	int t;
	for (t = 0; t < T; t++){
		char s[501];
		scanf("%s",s);
		int count[500];
		int k;
		for (k = 0; k < 500; k++){
			count[k] = 1;
		} 
		char alpha[500];
		int plOfS = 0;
		int plOffCnt = 0;
		int cnt = 1;
		int i;
		for (i = 0; i < strlen(s); i++,plOfS++){
			if (s[plOfS] == s[plOfS + 1]){
				cnt++;
			}else{
				if(cnt > 255){
					alpha[plOffCnt] = s[plOfS];
					count[plOffCnt] = 255;
					plOffCnt++;
					alpha[plOffCnt] = s[plOfS];
					count[plOffCnt] = cnt - 255;
				}else{
					alpha[plOffCnt] = s[plOfS];
					count[plOffCnt] = cnt;
				}
				cnt = 1;
				plOffCnt++;
			}
		}
		int j;
		printf("case #%d:\n",t);
		for (j = 0; j < plOffCnt; j++){
			printf("%d",count[j]);
			printf("%c",alpha[j]); 
		}
		printf("\n");
	}
	return 0;
}