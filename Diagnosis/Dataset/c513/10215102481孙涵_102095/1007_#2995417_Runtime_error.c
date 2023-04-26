# include <stdio.h>
# include <stdlib.h>
# include <string.h>


int* baseconvertion(int N, int *len);
int findLongestString (int *p, int *len);

int main(){
    int T;
    scanf("%d",&T);
    int count;
    for (count = 0; count < T; count++){
        int N;
        int len;
        scanf("%d",&N);
        int *p;
        p = baseconvertion(N, &len);
        printf("case #%d:\n",count);
        int max = findLongestString(p, &len);
        printf("%d\n",max);
    }
    return 0;
}

int* baseconvertion(int N, int *len){
    int baseR[100] = {0};
    int num;
    int pl = 0;
    do{
        num = N % 2;
        N = (N-num)/2;
        baseR[pl]= num;
        pl++;
    }while(N > 0);
    *len = pl;
    int i;
    for (i = 0; i < (*len/2); i++){
    	int temp = baseR[i];
    	baseR[i] = baseR[ (*len)-1-i ];
    	baseR[ (*len)-1-i ] = temp;
	}
	int *p;
//	p = (int *)malloc(sizeof(int)*(*len));
	p = baseR;
	return p;
}

// 查找最长的子字符串 

int findLongestString (int *p, int *len){
	int i, j;
	int count = 1;
	int max = 1;
	for (i = 0; i < (*len); i++){
		for (j = i; j < (*len) - 1; j++){
			if ((*(p + j)) == (*(p + j + 1))){
				count++;
			}
			if (count > max){
				max = count;
			}
		}
	}
	return max;
} 