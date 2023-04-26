# include <stdio.h>
# include <stdlib.h>
# include <string.h>

/*
十进制转R进制
首先需要一个读要转换多少次
然后需要一个具体的进制转换
然后printf换行
*/
void baseconvertion(int N, int R);

int main(){
    int T;
    scanf("%d",&T);
    int count;
    for (count = 0; count < T; count++){
        int N,R;
        scanf("%d%d",&N,&R);
        baseconvertion(N,R);
    }
    return 0;
}

//baseconvertion

//A = 65 1 = 49;

// N--待转换整数 R--目标进制
void baseconvertion(int N, int R){
    char baseR[100] = {0};
    char s;
    int num;
    int sign;
    if(N<0){
    	sign = -1;
    	N = -N;
	}
    int pl = 0;
    do{
        num = N % R;
        N = (N-num)/R;
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
    for(; len >= 0; len --){
        printf("%c",baseR[len]);
    }
    printf("\n");
}