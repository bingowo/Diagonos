#include <stdio.h>
#include <stdlib.h>
static int cmp(const void* a, const void* b);
int main(){
    int T, n, m, L, U;
    scanf("%d", &T);
    for(int i = 0; i<T; i++)
    {
        scanf("%d %d", &n, &m);
         
        int* array = (int*)malloc(sizeof(int)*(n+1));
        int* sub = (int*)malloc(sizeof(int)*(n*(n+1)/2));
        for(int j = 1; j <= n; j++){
            scanf("%d", &array[j]);
        }
        int index = 0;
        for(int len = 1; len <= n; len++){
            for(int j = 1; j <= n-len+1; j++){
            	int sum = 0;
                for(int k = j; k <= j+len-1; k++){
                	sum += array[k];
				}
				sub[index++] = sum;
            }
        }

		printf("case #%d:\n", i);
		qsort(sub, n*(n+1)/2, sizeof(int), cmp);
		for(int j = 0; j<m; j++){
			scanf("%d %d", &L, &U);
			int sum = 0;
			for(int k = L-1; k < U; k++){
				sum += sub[k];
			}
			printf("%d\n", sum);
		}
    }
    return 0;
}
static int cmp(const void* a, const void* b){
	return *((int*)a) - *((int*)b);
}