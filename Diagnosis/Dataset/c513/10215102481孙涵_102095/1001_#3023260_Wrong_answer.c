#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


//int main(int argc, char *argv[]) {
//	int T,t;
//	scanf("%d",&T);
//	for(t = 0; t < T; t++){
//		char s[20];
//		scanf("%s",s);
//		int i;
//		int len = strlen(s);
//		int start[20],ans[20],res[20];
//		start[0] = len;
//		for(i = 1; i <= len; i++){
//			if(s[i - 1] >= '0' && s[i - 1] <= '9'){
//				start[i] = s[i - 1] - '0';
//			}
//		}
//		memset(res,0,sizeof(res));
//		int y,m,j;
//		while(start[0] >= 1){
//			y = 0;
//			m = 1;
//			ans[0] = start[0];
//			while(i <= start[0]){
//				y = y * 10 + start[i];
//				ans[m++] = y / 2333;
//				y %= 2333;
//			}
//			res[++res[0]] = y;
//			m = 1;
//			while ((m <= ans[0]) && (ans[m]) == 0){
//				m++;
//			}
//			memset(start,0,sizeof(start));
//			for(j = m;j <= ans[0];j++){
//				start[++start[0]] = ans[j]; 
//			}
//        	memset(ans,0,sizeof(ans));
//		}
//		int k;
//		for (k = 0; k >= 0; k--){
//			printf("%d ",res[k]);
//		} 
//		printf("\n");
//	} 
//}



# include <stdio.h>
# include <stdlib.h>
# include <string.h>

void baseconvertion(int N);

int main(){
    int T;
    scanf("%d",&T);
    int count;
    for (count = 0; count < T; count++){
        int N,R;
        scanf("%d",&N);
        baseconvertion(N);
    }
    return 0;
}

void baseconvertion(int N){
    char baseR[100] = {0};
    char s;
    int num;
    int sign = 0;
    if(N < 0){
    	sign = -1;
    	N = -N;
	}
    int pl = 0;
    do{
        num = N % 2333;
        N = (N-num)/2333;
        if(num > 9){
            num = num + 55;
        }else{
            num = num + 48;
        };
        baseR[pl]= num;
        pl++;
    }while(N > 0);
    int len = strlen(baseR) - 1;
    if(sign == -1){
    	printf("-");
	}
    for(; len > 0; len --){
        printf("%c",baseR[len]);
    }
    printf("\n");
}
