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
        long long* sub = (long long*)malloc(sizeof(long long)*(n*(n+1)/2));
        array[0] = 0;
        for(int j = 1; j <= n; j++){
            scanf("%d", &array[j]);
            array[j] += array[j-1];//使得每一项都是前n项和
        }
        int index = 0;
        for(int len = 1; len <= n; len++){//len指子集的长度
            for(int j = 1; j <= n-len+1; j++){//通过前缀和去求出每一个子集的和
				sub[index++] = array[j+len-1] - array[j-1];
            }
        }
		qsort(sub, index, sizeof(long long), cmp);//把子集和排序
		for(int i = 1; i<index; i++){//再把子集的和给构造为前缀和
		    b[i] += b[i-1];
		}
		printf("case #%d:\n", i);
		for(int j = 0; j<m; j++){
			scanf("%d %d", &L, &U);
			printf("%lld\n", sub[U] - sub[L-1]);
		}
    }
    return 0;
}
static int cmp(const void* a, const void* b){
	return *((int*)a) - *((int*)b);
}