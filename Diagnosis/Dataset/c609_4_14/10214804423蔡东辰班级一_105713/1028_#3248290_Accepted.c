#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct{
    int row[50];
    int len;
}R;
static int cmp(const void* a, const void* b){
    R x = *((R*)a);
    R y = *((R*)b);
    int len = (x.len<y.len)? x.len:y.len;
    for(int i = 0; i<len; i++){
        if(x.row[i] == y.row[i]){
            continue;
        }
        return y.row[i] - x.row[i];
    }
    return y.len - x.len;
}
int main(){
    int T, N, cnt, x, temp[500];
    scanf("%d", &T);
    for(int i = 0; i<T; i++){
        scanf("%d", &N);
        R* l = (R*)malloc(sizeof(R)*N);//装下N行
        for(int j = 0; j<N; j++){//N行的输入
        	cnt = 0;//每一行的计数
            while(1){
                scanf("%d", &l[j].row[cnt++]);
                if(l[j].row[cnt-1] == -1){break;}
           }
           l[j].len = cnt-1;
        }
        qsort(l, N, sizeof(R), cmp);
        for(int j = 0; j<N; j++){
            for(int k = 0; k<l[j].len; k++){
            	printf("%d", l[j].row[k]);
            	if(k!=l[j].len-1){
            		printf(" ");
				}
			}
			printf("\n");
        }
    }
    return 0;
}