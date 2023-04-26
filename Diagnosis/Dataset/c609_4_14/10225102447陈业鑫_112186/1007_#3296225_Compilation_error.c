#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}//升序排序
int num1(long long int a){//统计1的个数//位运算
    int cn = 0;
    long long int ln = 1;
    if(a==0)return 0;
    for(int time = 0;time<64;time++){
        if(a&ln!=0)cn++;
        ln = ln<<1;
    }
    return cn;
}
int find(int *b, int num){
    int max = 0;
    for(int i=0;i<num;i++){
        if(b[max]<b[i]){
            max = i;
        }
    }
    b[max] = -1;
    return max;
}
void sort(long long int *a, int *b, int num, long long int *c){//排序//按b[i]中从大到小排序，同时对应的a[i]也随之排序，b[i]相同，按a[i]从小到大排序，返回排好序的a于c中
	int d[10000] = {0};
	for(int i=0;i<num;i++){
		d[i] = find(b, num);//find返回b中最小值的位置
	}
	for(int i=0;i<num;i++){
		c[i] = a[d[i]];
	}
}

int main(){
	int num = 0;
	int problem_num[10] = {0};
	long long int getn[10][10000] = {0};
	int numone[10][10000] = {0};
	long long int ret[10][10000] = {0};
	scanf("%d", &num);
	for(int i = 0;i<num;i++){
		scanf("%d", &problem_num[i]);
		for(int j = 0;j<problem_num[i];j++){
			scanf("%lld", &getn[i][j]);	
		}
		qsort(getn[i], problem_num[i],sizeof(int), cmpfunc);
		for(int k=0;k<problem_num[i];k++){
		    numone[i][k] = num1[getn[i][k]];
		}
		sort(getn[i], numone[i], problem_num[i], ret[i]);
	}
	for(int i=0;i<num;i++){
		printf("case #%d:\n", i);
		for(int j=0;j<problem_num[i];j++){
			printf("%lld ", ret[i][j]);
		}
		printf("\n");
	}
	return 0;
}