#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int num[51];
}vector;

int cmp(const void *a, const void *b)
{
	vector *pa = (vector *)a;
	vector *pb = (vector *)b;
	int index = 0;
	for(; pa->num[index] == pb->num[index]; index ++);
	return pb->num[index] - pa->num[index]; 
}

int main(void)
{
	int t;
	scanf("%d", &t);
	for(int i = 0 ; i < t; i ++){
		int n;
		scanf("%d", &n);
		vector line[n];
		for(int j = 0 ; j < n ; j ++){
			int temp = 0;
			for(int k = 0 ; k < 51 && temp != -1; k ++){
				scanf("%d", &temp);
				line[j].num[k] = temp;
			}
		}
		qsort(line, n, sizeof(vector), cmp);
		for(int j = 0 ; j < n ; j ++){
			for(int k = 0 ; k < 51 && line[j].num[k] != -1; k ++){
				if(line[j].num[k] != -1){
					printf("%d%c", line[j].num[k], line[j].num[k + 1] == -1 ? '\n' : ' ');
				}
			}
		}
	}
}
