/*
Created by Shizumu on 2022-03-14
	这个题目要完成应该是很简单的，只要不断枚举就可以做完（似乎给了3.0sec，
时间比较充足）。但是在很多地方我们可以考虑优化，这在解决其他问题很有好处。	
*/ 
#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long int llu;
int cmp(const void *a, const void *b){ return *(int *)a - *(int *)b;}

int main(void)
{
	int t;
	scanf("%d", &t);
	for(int i = 0 ; i < t; i ++){
		int n, m;
		scanf("%d %d", &n, &m);
		int a[n], newa[(n * (n + 1)) / 2];
		for(int j = 0 ; j < n ; j ++){
			scanf("%d", &a[j]);
			/*为新构建一个数组做铺垫
			  ps:如果思考复杂点或许能够考虑用“前缀和”简化运算，但这里 
			  并没有使用这个 */
			newa[j] = a[j];
		}
		for(int j = 0, idx = n; j < n; j ++){
			for(int k = j + 1; k < n; k ++){
				//通过已有的项快速构建后面的项，节约时间 
				newa[idx] = a[k] + newa[idx - (n - j)];
				idx ++;
			}
		}
//		打印新生成的数列 
//		for(int j = 0 ; j < (n * (n + 1)) / 2; j ++){
//			printf("%d ", newa[j]);
//		}
//		printf("\n______________________\n");
		qsort(newa, n * (n + 1) / 2, sizeof(int), cmp);
		printf("case #%d:\n", i);
		llu l, u, sum = 0;
		for(int j = 0 ; j < m ; j ++){
			scanf("%d %d", &l, &u);
			sum = 0;
			for(int k = l - 1; k < u; k ++){
				sum += newa[k];
			}
			printf("%llu\n", sum);
		}
	}
	
	return 0;
}
