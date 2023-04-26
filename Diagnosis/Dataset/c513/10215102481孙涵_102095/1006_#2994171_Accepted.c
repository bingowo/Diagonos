#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void baseconvertion(char N[]);
int main(){
    int T;
    scanf("%d",&T);
    int count;
    for (count = 0; count < T; count++){
        char N[15];
        scanf("%s",&N);
        printf("case #%d:\n",count);
        baseconvertion(N);
    }
    return 0;
}

void baseconvertion(char N[]){
	int count;
	int len = strlen(N)-1;
	int num = 0;
	int num3 = 1;
	int flag = 0;
	char *p = N;
	for (; len >= 0; len--){
		if (*(p + len) == '-'){
			num = num + (-1)*num3;
		}else if (*(p +len) == '0'){
		}else{
			num = num + num3;
		}
		num3 = num3*3;
	}
	printf("%d\n",num);	
}